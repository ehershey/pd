// seeker (ressurect) 05/17/2000
// resurrect players
#include <daemons.h>
inherit DAEMON;
int spell();

string *unressable = ({ "demon", "lich", "dragon" });

int cmd_resurrect(string str)
{
    object ob, cor; 
    object *inv;
    int i, x, stat_charge;

    if (!spell()) {
	write("Only those strong in their faith may do this.");
	return 1;
    }
    if (!str || str=="")
    {
	write("Resurrect what?");
	return 1;
    }
    if (this_player()->query_mp() < 700) 
	return notify_fail("You do not have enough magical power to ressurect.\n");
    if (this_player()->query_ghost())
    {
	write("How about getting yourself a resurrect first?");
	return 1;
    }
    ob = find_living(str);
    if (!ob) 
    {
	write("Could not find anybody by that name.");
	return 1;
    }
    if (!ob->is_player()) {
	write("You cannot resurrect non-players.");
	return 1;
    }

    if (!ob->query_ghost())
    {
	write("You cannot resurrect the living.");
	return 1;
    }
    cor = present("corpse", environment(this_player()));
    if (!cor)
    {
	write("You must resurrect "+ob->query_cap_name()+" into a body.");
	return 1;
    }

    if (cor->query_old_race()=="lich")
	ob->move(environment( this_player() ));

    i = sizeof(unressable);
    while(i--)
    {
	if (cor->query_old_race() == unressable[i])
	{
	    write(capitalize(cor->query_old_race())+"s may not be ressurected.");
	    this_player()->set_mp(1);
	    return 1;
	}
    } 
    if (cor->query_old_race() != ob->query_race())
    {
	stat_charge = 1;
    } else {
	stat_charge = 0;
    }
    if(member_array(cor->query_old_race(), (string *)RACE_D->query_races()) == -1) {
	write("You failed to resurrect "+ob->query_cap_name()+".");
	this_player()->set_mp(1);
	return 1;
    }

    ob->move(environment( this_player() ));
    message("info", "%^YELLOW%^%^BOLD%^You have been resurrected from the dead!%^RESET%^", ob);
    write("%^YELLOW%^%^BOLD%^You resurrect "+ob->query_cap_name()+" from the dead!%^RESET%^");
    message("info", "%^YELLOW%^%^BOLD%^"+ this_player()->query_cap_name()+" resurrects "+ob->query_cap_name()+" from the dead!", environment(this_player()), ({ this_player(), ob }) );
    ob->revive();
    ob->set_race(cor->query_old_race());
    ob->new_body();
    ob->set_ghost(0);
    ob->add_hp(10);
    ob->set_heart_beat(1);
    ob->set_heal_rate(2);
    if (stat_charge) {
	x = ((int)ob->query_level()-1)/5;
	ob->set_stats((int)ob->query_stats("strength")-x);
	ob->set_stats((int)ob->query_stats("constitution")-x);
	ob->set_stats((int)ob->query_stats("dexterity")-x);
	ob->set_stats((int)ob->query_stats("charisma")-x);
	ob->set_stats((int)ob->query_stats("intelligence")-x);
	ob->set_stats((int)ob->query_stats("wisdom")-x);
    }
    this_player()->set_hp(5);
    this_player()->set_sp(5);
    this_player()->set_mp(5);
    i = (ob->query_level()*5000)*((ob->query_level()/10)+1);
    ob->add_exp(i);
    inv = all_inventory(cor);
    this_player()->add_skill_points("healing", i/2);
    i = sizeof(inv);
    while(i--)
    {
	inv[i]->move(ob);
    }
    cor->remove();
    return 1;

}

int spell() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_class() != "cleric") return 0;
    if (o->query_level() < 20) return 0;
    if (o->query_skill("faith") < 70) return 0;
    if (o->query_mp() < 700) return 0;
    return 1;
}
