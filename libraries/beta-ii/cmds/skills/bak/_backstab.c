#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_backstab(string str) {
    object *weapons, *knives;
    object victim;
    int *wc;
    string *type;
    int i, tmp;

    if (!abil()) {
	return notify_fail("What?\n");
    }

    if(!str) {
	notify_fail("Backstab whom?\n");
	return 0;
    }

    if (this_player()->query_class() != "rogue") {
	write("Only rogues may backstab.");
	return 1;
    }
    if (this_player()->query_rest_type()) {
	write("You can't do that while not on your feet.");
	return 1;
    }
    if(this_player()->query_ghost()) {
	notify_fail("You appear to be dead.\n");
	return 0;
    }

    if(this_player()->query_disable()) return 1;

    if(environment(this_player())->query_property("no attack")) {
	notify_fail("Some mystical force prevents you from that.\n");
	return 0;
    }
    if(this_player()->query_sp() < 25) {
	notify_fail("You are too tired to backstab.\n");
	return 0;
    }
    if((int)this_player()->query_skill("murder") < 5 || !(string)this_player()->query_class()) {
	notify_fail("Don't you wish you were fast enough for that?\n");
	return 0;
    }
    if(!(victim = present(lower_case(str),environment(this_player())))) {
	notify_fail("You don't see the target here.\n");
	return 0;
    }
    if(victim == this_player()) {
	notify_fail("Backstab yourself?\n");
	return 0;
    }
    if(victim->query_ghost()) {
	notify_fail("Backstab whom?\n");
	return 0;
    }
    if(!living(victim)){
	notify_fail("You would look silly backstabbing that.\n");
	return 0;
    }

    if (this_player()->query_current_attacker()){
	notify_fail("You are already in combat.\n");
	return 0;
    }

    wc = ({});
    type = ({});
    knives = ({});
    weapons = (object *)this_player()->query_wielded();

    for(i=0, tmp = sizeof(weapons); i<tmp; i++) {
	if((string)weapons[i]->query_type() != "knife") continue;
	type += ({(string)weapons[i]->query_type() });
	wc += ({ (int)weapons[i]->query_wc() });
	knives += ({ weapons[i] });
    }
    if(!sizeof(knives)) {
	write("You are not equipped for backstabbing.");
	return 1;
    }
    this_player()->set_disable();

    if(member_array(victim, (object *)this_player()->query_hunted()) != -1 ||
      member_array(victim, (object *)this_player()->query_attackers())!=-1) {
	notify_fail("You have lost the element of surprise!\n");
	return 0;
    }

    if(this_player()->query_current_attacker()) {
	notify_fail("You are already in combat with something else!\n");
	return 0;
    }

    if(victim->is_player() && !interactive(victim)) return 0;

    if (victim->query_skill("perception") + victim->query_stats("wisdom") >
      this_player()->query_skill("stealth"))
	tell_object(victim, "%^ORANGE%^"+this_player()->query_cap_name()+" attempts to sneak behind you unnoticed!");

    this_player()->set_paralyzed(1,"You are concentrating on backstabbing.");

    call_out("do_dmg", 1, victim, this_player());

    write("%^ORANGE%^You sneak around behind "+victim->query_cap_name()+"!%^RESET%^");

    return 1;
}
int do_dmg(object victim) {
    int i, tmp, *wc, dex;
    object *weapons, *knives, tp;
    string tt, tk, *type;
    int j, spUse;
    float mod = 0;
    if (!victim){
	write("Your target is not here.");
	tell_room(environment(this_player()), this_player()->query_cap_name()+" grumbles.", ({ this_player() }));
	return 1;
    }

    if (environment(this_player()) != environment(victim)){
	write("Your target is not here.");
	tell_room(environment(this_player()),
	  this_player()->query_cap_name()+" grumbles.", ({ this_player() }));
	return 1;
    }

    if(!this_player()->kill_ob(victim)) {
	write(victim->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }

    if (random(victim->query_stats("dexterity")/2) +
      (victim->query_stats("dexterity")/2) >
      this_player()->query_stats("dexterity") + 5 ) 
    {
	write("%^ORANGE%^Your backstab misses!%^RESET%^");
	say(this_player()->query_cap_name()+" misses an attempt to backstab "
	  +(string)victim->query_cap_name(), victim);
	tell_object(victim, "%^ORANGE%^"+this_player()->query_cap_name()+" misses an attempt to backstab you!%^RESET%^");
	return 1;
    }

    wc = ({});
    type = ({});
    knives = ({});
    weapons = (object *)this_player()->query_wielded();
    for(i=0, tmp = sizeof(weapons); i<tmp; i++) {
	if((string)weapons[i]->query_type() != "knife") continue;
	type += ({(string)weapons[i]->query_type() });
	wc += ({ (int)weapons[i]->query_wc() });
	knives += ({ weapons[i] });
    }

    tt = victim->return_target_limb();

    write("%^ORANGE%^You backstab "+victim->query_cap_name()+"!%^RESET%^");

    tk = knives[sizeof(knives)-1]->query_name();

    if (!tk) tk = "knife";

    write("%^BOLD%^%^ORANGE%^Your "+tk+" sinks deep into "+(string)victim->query_cap_name() + "'s "+tt+".%^RESET%^");
    say("%^ORANGE%^"+this_player()->query_cap_name() +"'s attempt to backstab "+victim->query_cap_name() 
      + " hits home!%^RESET%^", victim);
    tell_object(victim, "%^ORANGE%^%^BOLD%^"+this_player()->query_cap_name()+"'s knife sinks deep into your back!%^RESET%^");

    /****( Damage: )***********************************************/

    if (this_player()->query_level() > 1)
    {
	j = BALANCE_D->get_damage( this_player(), victim, 2, ({ "murder", "agility", "attack" }),
	  ({ "strength", "dexterity" }) );
	//mod = (7 / 4);
	spUse = j / 7;
    }
    if (this_player()->query_level() >= 20)
    {
	j = BALANCE_D->get_damage( this_player(), victim, 3, 
	  ({ "murder", "murder", "agility", "agility", "attack", "stealth" }),
	  ({ "strength", "dexterity", "dexterity" }),
	  ({ "strength", "dexterity" }));
	//mod = 2;
	spUse = j / 7;
    }
    if (this_player()->query_level() > 36)
    {
	j = BALANCE_D->get_damage( this_player(), victim, 4, 
	  ({ "murder", "murder", "agility", "agility", "attack", "stealth" }),
	  ({ "strength", "dexterity", "dexterity" }),
	  ({ "strength", "dexterity", "dexterity" }));
	//mod = (7 / 3);
	spUse = j / 8;
    }
    if (this_player()->query_level() > 55)
    {
	j = BALANCE_D->get_damage( this_player(), victim, 4, 
	  ({ "murder", "murder", "agility", "agility", "attack", "stealth" }),
	  ({ "strength", "dexterity", "dexterity" }),
	  ({ "strength", "dexterity", "dexterity" }));
	j = j * 4 / 3;
	//mod = (5 / 2);
	spUse = j / 9;
    }
    /**************************************************************/
    /******(mod)***************************************************/
    tp = this_player();
    dex = tp->query_stats("dexterity");
    if(dex < 30) mod = (7 / 4);
    else if(dex < 50) mod = (19 / 10);
    else if(dex < 70) mod = 2;
    else if(dex < 100) mod = (21 / 10);
    else if(dex < 120) mod = (11 / 5);
    else if(dex < 150) mod = (23 / 10);
    else if(dex < 190 ) mod = (  24/10);
    else if(dex < 240) mod = (  25/10);
    else if(dex < 300) mod = (  26/10);
    else mod = (27/10);

  if (this_player()->query_name() == "nulvect") printf("\n%f\n", mod);

    /**************************************************************/

    this_player()->add_skill_points("murder", j/50);

    victim->damage(j*mod);

    //victim->check_on_limb(tt);

    if (!wizardp(this_player()))
	this_player()->add_alignment(-5);

    this_player()->add_sp(-spUse);
/*
    if(random(10000) == 127) {
	write("Your " +tk+ " breaks!");
	message("room_break", this_player()->query_cap_name()+ "'s "+tk+" breaks!", environment(this_player()), this_player());
	knives[sizeof(knives)-1]->remove();
    }
*/

    if(victim->query_hp() < 0)
	victim->heart_beat();
    return 1;
}

void help() {
    write("Syntax: backstab <enemy>\n\n"
      "This command is used to initiate combat with the\n"
      "monster or player you specify.\n"
    );
}

int abil() {
    object tp;
    tp = this_player();
    if (tp->query_class() != "rogue") return 0;
    if (tp->query_subclass() == "scout") return 0;
    if (tp->query_subclass() == "thug") return 0;
    if (tp->query_skill("agility") < 5) return 0;
    if (tp->query_skill("murder") < 5) return 0;
    return 1;
}
