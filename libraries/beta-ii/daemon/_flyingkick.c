#include <std.h>
#include <rest.h>
#include <daemons.h>

inherit DAEMON;

int abil();

int cmd_flyingkick(string str) {
    object victim, rm, tp;
    string dir, mob, *dirlist;
    int i, tmp;
    
    if (!abil()) 
        return notify_fail("What?\n");

	tp = this_player();
	
    if(!str)
        return notify_fail("Pounce whom?\n");
        
    if(!sizeof(dirlist = environment(tp)->query_exits()))
    	return notify_fail("There is no way out of here!.\n");

    if(sscanf(str, "%s %s" , mob, dir ) != 2)
		return notify_fail("Syntax: flyingkick <target> <direction>\n");	
    
   	if(member_array(dir, dirlist) == -1)
		return notify_fail("That is not a direction!\n");
    
    if(dir != "north" && dir != "northeast" && dir != "east"
    	&& dir != "southeast" && dir != "south" && dir != "southwest"
    	&& dir != "west" && dir != "northwest")
			return notify_fail("You can not jump in that direction!\n");	
	
	if(!(rm = find_object(environment(tp)->query_exit(dir))))
      	return notify_fail("You cannot jump in that direction.\n");

	if(!(victim = present(mob, rm)))
		return notify_fail("That doesn't seem to be "+dir+".\n");

    if (tp->query_rest_type())
        return notify_fail("You are not in a position to perform that action\n");

    if(tp->query_ghost())
        return notify_fail("You appear to be dead.\n");

    if(tp->query_disable()) 
		return notify_fail("You are busy.\n");
    
    if(environment(tp)->query_property("no attack"))
        return notify_fail("Some mystical force prevents you from that.\n");

    if(tp->query_sp() < 25)
        return notify_fail("You are too tired to jump kick your victim.\n");
        
    if(victim == tp)
        return notify_fail("This seems impossible, tell an imm.\n");

    if(!living(victim))
        return notify_fail("You can not jump kick that.\n");
	
	/*
    if(member_array(victim, (object *)this_player()->query_hunted()) != -1 ||
        member_array(victim, (object *)this_player()->query_attackers())!=-1) {
            return notify_fail("You have lost the element of surprise!\n");
    }
    Leaving this out for now.
    */
    
    if(tp->query_current_attacker())
        return notify_fail("You are already in combat with something else!\n");
    
    if(victim->is_player() && !interactive(victim)) return 0;
    
    tp->set_disable();
    
    tp->set_paralyzed(2,"You are concentrating on your jump kick.");
    
    write("%^BOLD%^You start running to the %^GREEN%^"+dir+"%^RESET%^!%^RESET%^");
    message("room", "%^BOLD%^"+tp->query_cap_name()+
    	" sprints to the %^GREEN%^"+dir+"%^RESET%^!%^RESET%^", environment(tp), tp);
    
    call_out("do_jump", 1, victim, tp, rm, dir);
    
    return 1;
}

int do_jump(object victim, object tp, object rm, string dir)
{
	if(!tp)
		return 1;
	if(!victim)
		return notify_fail(victim->query_cap_name()+ " seems to be gone!\n");
	if(!rm)
		return notify_fail("Umm..... the room is gone.... tell an imm.");
		
	write("%^BOLD%^You jump off the ground and fly to the %^GREEN%^"+dir+"%^RESET%^!%^RESET%^\n");
	message("room", "%^BOLD%^"+tp->query_cap_name()+
		" jumps off the ground and flys to the %^GREEN%^"+dir+"%^RESET%^!%^RESET%^"
		, environment(tp), tp);
	call_out("do_dmg", 1, victim, tp, rm);
}


int do_dmg(object victim, object tp, object rm) {
    int i, tmp, dex;
    string tt, tk;
    int j, spUse;
    
    if(!rm)
    	return notify_fail("Umm..... the room is gone.... tell an imm.");
    	
    tp->move(rm);
    
    write("%^BOLD%^You %^BLUE%^fly%^WHITE%^ into the room!%^RESET%^");
    message("room", "%^BOLD%^" +tp->query_cap_name()+
    	" comes %^BLUE%^flying%^WHITE%^ into the room!", environment(tp), tp);
    
    if (!victim)
        return notify_fail("Your target is gone.");
    
    if (environment(tp) != environment(victim))
        return notify_fail("Your target is not here!\n");
    
    if(environment(tp)->query_property("no attack") 
		|| environment(tp)->query_property("safe"))
    {
		write("You fall to the ground!");
		message("room", tp->query_cap_name()+ " falls to the ground!", environment(tp), tp);	
		return 1;
	}
    
    if(tp->query_attackers())
    {
		for(int q = 0; q < sizeof(tp->query_attackers()); q++)
		{
			if(victim == tp->query_attackers()[q])
			{
		        write("%^BOLD%^You miss your kick!%^RESET%^");
        		message("room","%^BOLD%^"+tp->query_cap_name()+" misses an attempt to kick "
            		+(string)victim->query_cap_name()+"!%^RESET%^", environment(tp),({tp,victim}));
		        tell_object(victim, "%^BOLD%^"+tp->query_cap_name()+" misses an attempt to kick you!");
        		return 1;	
			}	
		}	
	}
    
    if(!tp->kill_ob(victim)) 
	{
        write(victim->query_cap_name()+" can't be attacked by you yet.");
        return 1;
    }
    
    if (random(victim->query_stats("dexterity")/2) +
            (victim->query_stats("dexterity")/2) >
            tp->query_stats("dexterity") + 5 ) 
    {
        write("%^BOLD%^You miss your kick!%^RESET%^");
        message("room","%^BOLD%^"+tp->query_cap_name()+" misses an attempt to kick "
            +(string)victim->query_cap_name()+"!%^RESET%^", environment(tp),({tp,victim}));
        tell_object(victim, "%^BOLD%^"+tp->query_cap_name()+" misses an attempt to kick you!");
        return 1;
    }
    
    tt = victim->return_target_limb();
    
    write("%^BOLD%^You %^RED%^l%^RESET%^%^RED%^a%^BOLD%^n%^RESET%^%^RED%^d%^BOLD%^%^WHITE%^ your %^YELLOW%^kick%^WHITE%^ on "+victim->query_cap_name()+", hitting "
		+victim->query_objective()+
		" in the "
		+victim->return_target_limb()+
		"!%^RESET%^");

    message("room","%^BOLD%^"+tp->query_cap_name() +" %^RED%^l%^RESET%^%^RED%^a%^BOLD%^n%^RESET%^%^RED%^d%^BOLD%^s%^WHITE%^ a kick on "+victim->query_cap_name()+
    	", %^YELLOW%^kicking%^WHITE%^ "
		+victim->query_objective()+
		" in the "
		+victim->return_target_limb()+
		"!%^RESET%^"
		, environment(tp), ({tp,victim}));
		
    tell_object(victim, "%^BOLD%^"
		+tp->query_cap_name()+
		" lands a %^YELLOW%^kick%^WHITE%^ on you, %^RED%^hitting%^WHITE%^ you in the "
		+victim->return_target_limb()+
		"!%^RESET%^"
		);

    /****( Damage: )***********************************************/

	 j = BALANCE2_D->get_Pdamage( this_player(), victim, 1, ({ "attack", "perception", "perception" }),
            ({ "dexterity", "dexterity", "strength" }), ({"dexterity"}) );    
	 j = j * 2;
    /**************************************************************/

    if(j < 1) j = 1;
    if(j > 600) j = 600 + tp->query_level();

	if(tp->query_class() != "scout")
		j = 2*j/3;
	
    if(tp->query_skill("perception") > victim->query_skill("defense") && tp->query_class() == "scout")
    {
        if(tp->query_stats("dexterity") > 3*(victim->query_stats("dexterity"))/2)
        {
			if(random(3) < 2 && !victim->query_paralyzed()) 
             victim->set_paralyzed(2, "You are stunned from the kick!");
             victim->set_rest_type(LAY);
        }
    }

    tp->add_skill_points("attack", j/20);
    tp->add_skill_points("perception", j/20);
	    
    victim->damage(j);
    
	tp->add_sp(-(tp->query_skill("perception")/5 + (1+random(tp->query_stats("dexterity")/3))));
    
    if(victim->query_hp() < 0)
        victim->heart_beat();
    return 1;
}

void help() {
    write("Syntax: flyingkick <enemy> <direction>\n\n"
      "Someone aware of their surroundings can leap at an enemy "
	  " from another area, landing a powerful kick if timed right.\n"
    );
}

int abil() {
    object tp;
    tp = this_player();
    if(tp->query_skill("perception") < 60) return 0;
    if(tp->query_skill("attack") < 50) return 0;
    
    return 1;
}
