//  Drink Command
//  Spell/Skill for Vampires
//  If level is greater than 20, then may drink without monster having low hp.
mapping bl;

float break_away(object tp, object vic) {
    int wis, intel, tot, tot2;
    float per;
    wis=vic->query_stats("wisdom");
    intel=vic->query_stats("intelligence");
    tot=(wis+intel)*2;
    tot2=( tp->query_stats("wisdom")+tp->query_stats("intelligence") )*2;
    if(tot >= tot2*3) return -1;
    if(tot >= tot2*2 && random(6)==5) return 100; // make auto
    if(tot >= tot2 && !random(16)) return 100; // make auto
    per=percent(tot, tot2);
    if(per>80 && random(2)) return per;
    return 0;
}
int abil();
int cmd_drink(string s) {
    object tp, vic;
    float per, per2;

    tp=this_player();
    if(!abil()) return 0;
    if(!s) return notify_fail("Syntax: <drink [victim]>\n");
    if(s=="stop") {
	if(!bl[tp]) {
	    write("You are not drinking anyones blood right now.\n");
	    return 1;
	}
	write("You decide to stop drinking "+bl[tp]->query_cap_name()+"'s blood.\n");
	bl[tp]->set_paralyzed(0);
	if(present("drink_ob", tp)) present("drink_ob", tp)->remove();
	map_delete(bl, tp);
	return 1;
    }
    if(bl && bl[tp]) {
	write("You are already drinking the blood of another.\n");
	return 1;
    }
    if(environment(tp)->query_property("no attack")) return notify_fail("You may not drink here.\n");
    if(tp->query_bp() >= tp->query_max_bp()) {
	write("There is no reason to drink blood.\n");
	return 1;
    }
    vic=present(s, environment(this_player()));
    if(!vic) {
	write("You do not see that here.\n");
	return 1;
    }
    if(!vic->ok_to_kill(vic)) {
	write("You may not drink blood from that.\n");
	return 1;
    }
    if(vic->is_corpse() || vic->id("remains")) {
	write("The blood in the corpse would not be satisfying.\n");
	return 1;
    }
    if(vic->query_race() == "vampire" || vic->is_undead()) {
	write("You may not drink the blood for a fellow undead.\n");
	return 1;
    }
    if( ( vic->query_level() < 20 || tp->query_level() < 20 ) && vic->is_player()) {
	write("You are too young to feast on that of the living player.");
	return 1;
    }
    if(!vic->is_living()) {
	write("You may not drink from the non-living.\n");
	return 1;
    }
    if(tp->query_arena() || vic->query_arena()) {
	write("You may not drain blood inside of the arena.\n");
	return 1;
    }
    per=percent(vic->query_hp(), vic->query_max_hp());
    if(tp->query_level() < 20 && per > 10) {
	write(vic->query_cap_name()+" isnt weak enough for you to drink their blood.\n");
	if(this_player()->query_name() == "whit") write("Percent: "+to_int(per)+" HP: "+vic->query_hp()+" Max HP: "+vic->query_max_hp()+".\n");
	return 1;
    }
    per=percent(vic->query_bp(), vic->query_max_bp());
    if(per < 10) {
	write(vic->query_cap_name()+" is too low on blood.\n");
	return 1;
    }
    if(per2=break_away(tp, vic)) {
	write("Your attempt to drink the blood from "+vic->query_cap_name()+" has failed!\n");
	if(per2==-1) {
	    message("", tp->query_cap_name()+" fails at the attempt to suck "
	      "your %^BOLD%^%^RED%^blood%^RESET%^.\n", vic);
	    vic->force_me("laugh at "+tp->query_name());
	}
	if(per2>90) {
	    message("", tp->query_cap_name()+" fails at the attempt to suck "
	      "your %^BOLD%^%^RED%^blood%^RESET%^.\n", vic);
	    vic->force_me("kill "+tp->query_name());
	}
	return 1;
    }
    write("You latch onto "+vic->query_cap_name()+"'s neck and begin to "
      "draw %^BOLD%^%^RED%^blood%^RESET%^.\n");
    tell_object(vic, this_player()->query_cap_name()+" grabs ahold of "
      "you and starts to suck your %^BOLD%^%^RED%^blood%^RESET%^.");
    message("", this_player()->query_cap_name()+" grabs ahold of "
      +vic->query_cap_name()+" and starts to suck "+vic->query_possessive()+" %^BOLD%^%^RED%^blood%^RESET%^.", 
      environment(tp), ({tp, vic}) );
    vic->set_paralyzed(400, "Your blood to being drained away, and are "
      "helpless to stop it.\n", "Having your blood almost completly drained, "+
      tp->query_cap_name()+" stops draining your blood.\n");
    tp->set_disabled(400); //  Stop combat for vampire.\n
    if(!bl) bl=([]);
    bl[tp]=vic;
    new("/std/obj/vampdrink")->move(tp);
    new("/std/obj/vampdrink")->move(vic);      

    call_out("con", 2);
    return 1;
}

void con() {
    int i, amt;
    object *key, tp, vic, *to_remove=({});
    float per, per2;

    i=sizeof(key=keys(bl));
    while(i--) {
	tp=key[i];
	vic=bl[key[i]];
	if(!present(vic, environment(tp))) {
	    vic->set_paralyzed(0);
	    if(present("drink_ob", tp)) present("drink_ob", tp)->remove();
	    write("Error occured while performing drink.  Error=Victim not Present.\n");
	    to_remove += ({ tp });
	    continue;
	}
	per=percent(vic->query_bp(), vic->query_max_bp());
	if(per < 10 || vic->query_bp() < 10) {
	    vic->set_paralyzed(0);
	    tp->set_disabled();
	    if(present("drink_ob", tp)) present("drink_ob", tp)->remove();
	    message("", "You stop draining "+vic->query_cap_name()+"'s blood.\n", tp);
	    message("", tp->query_cap_name()+" stops draining "+vic->query_cap_name()+"'s blood.\n",
	      environment(tp), ({tp, vic}));
	    to_remove += ({ tp });
	    continue;
	}
	if(tp->query_bp() == tp->query_max_bp()) {
	    vic->set_paralyzed(0);
	    tp->set_disabled(1);
	    if(present("drink_ob", tp)) present("drink_ob", tp)->remove();
	    message("", "You have reached your maximum blood compacity.\n", tp);
	    message("", tp->query_cap_name()+" stops draining "+vic->query_cap_name()+"'s blood.\n",
	      environment(tp), ({tp, vic}));
	    to_remove += ({ tp });
	    continue;
	}
	if(break_away(tp, vic)) {
	    message("", vic->query_cap_name()+" escapes your grasp!\b", tp);
	    message("", vic->query_cap_name()+" breaks away from "+tp->query_cap_name()+".\n", 
	      environment(tp), ({tp,vic}));
	    message("", "You get lucky and escape "+tp->query_cap_name()+"'s grasp!.\n", vic);
	    to_remove += ({tp});
	    continue;
	}
	per2=percent(tp->query_hp(), tp->query_max_hp());
	if(random(2)) {
	    if(per2 < 20) {
		message("", "You drink very hastily from "+vic->query_cap_name()+"!\n", tp);
		message("", tp->query_cap_name()+" continues to drink your %^BOLD%^%^RED%^blood%^RESET%^.\n", 
		  vic);
	    } else {
		message("", "The blood from "+vic->query_cap_name()+" tastes very good as it slides down "
		  "your throat.", tp);
		message("", tp->query_cap_name()+" continues to drink your %^BOLD%^%^RED%^blood%^RESET%^.\n", 
		  vic);
	    }
	}
	amt=random(10);
	if(!amt || amt==1) amt=2;
	tp->add_bp(amt);
	vic->add_bp(-amt);
	if(per2 < 20) {
	    amt=random(5);
	    if(!amt) amt=1;
	    tp->add_hp(amt);
	    vic->add_hp(-amt);
	}
    }
    i=sizeof(to_remove);
    while(i--) {
	this_object()->stop_drink(to_remove[i]);
    }
    if(keys(bl) != ({}) ) {
	remove_call_out("con");
	call_out("con", 2);
    }
}

int abil() {
    if(this_player()->query_race() == "vampire") return 1;
}

void help() {
    write("Syntax: <drink [victim]>\n\n"
      "This allows a vampire to suck the blood from its victims.  You may also <drink stop>"
      "to stop sucking blood from your victim.\n");
}

mapping query_bl() { return copy(bl); }

void stop_drink(object t) { 
    if(present("drink_ob", bl[t])) present("drink_ob", bl[t])->remove();
    map_delete(bl, t); 
    if(present("drink_ob", t)) present("drink_ob", t)->remove();
}

