//spell by Hermes
//Note: If anything goes wrong with the spell, the very first thing to do is to reset the gate map by doing: call player;set_gate
#include <std.h>
inherit DAEMON;
int cmd_tame(string str) 
{
	object tp, ob;
	int nature, skip, which, i, count;
	string what, level, name, bodtype, race, shorty, longy;
	object *inv;
	mapping gat = this_player()->query_gate();
	if (!abil()) 
	{
		write("What?\n");
		return 1;
	}
	if(!environment(this_player())->query_property("forest"))
	{
		return notify_fail("You're not in a forest... The calls of nature do not reach the animals.\n");
	}
	if(!gat)
	{
		gat=([]);
		gat["count"] = 0;
	}
	
	if (this_player()->query_arena()==1)
	{
		return notify_fail("That's not very nice.\n");
	}
	this_player()->set_magic_round(1);
	tp = this_player();
	if(tp->query_ghost()) 
	{
		notify_fail("Your voice is hollow.\n");
		return 0;
	}
	if (this_player()->query_disable())
		return notify_fail("You are busy.\n");
	if(environment(tp)->query_property("no magic")) 
	{
		notify_fail("Something seems to be blocking your concentration.\n");
		return 0;
	}
	if((int)tp->query_sp() < 150) 
	{
		notify_fail("You're to tired to concentrate.\n");
		return 0;
	}
	if(!str) 
	{
		ob = (object)tp->query_current_attacker();
		if(!ob) 
		{
			notify_fail("What are you going to tame?\n");
			return 0;
		}
	}
	else 
	{
		ob = present(str, environment(tp));
		if(!ob) 
		{
			sscanf(str, "%s %d", what, which);
			inv = all_inventory(environment(tp));
			for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) 
			{
				if(inv[i]->id(what)) 
				{	
					skip++;
					if(skip == which) 
						ob = inv[i];
				}
			}
			if(!ob) 
			{
			notify_fail("No "+str+" here!\n");
			return 0;
			}
		}
	}
	if(!living(ob)) 
	{
		notify_fail(ob->query_cap_name()+" is not a living thing!\n");
		return 0;
	}
	if(ob == tp) 
	{
		notify_fail("Down boy!\n");
		return 0;
	}
	if(ob->query_property("no_tame"))
	{
		notify_fail("You can not tame that.\n");
		return 0;
	}
	if(ob->is_player())
	{
		notify_fail("You cannot tame players.\n");
		return 0;
	}
	if(!this_player()->kill_ob(ob)) 
	{
		write(ob->query_cap_name()+" can't be attacked by you yet.");
		return 1;
	}
	count = gat["count"];
	if (count < 0)
	{
		count = 0;
		gat["count"] = count;
		tp->set_gate(gat);
	}	
	if(count > tp->query_skill("nature")/4)
	{
		notify_fail("The animal growls and attacks!");
		return 0;
	}
	if(ob->query_level() > tp->query_level()/2)
	{
		notify_fail("The animal you're trying to tame looks at you for a moment then breaks free, attacking you!\n");
		return 0;
	}
		if(count > 8)
	{
		notify_fail("As you are already straining to keep your charges under control, the creature turns wild and attacks you!\n");
		return 0;
	}
	level = ob->query_level();
	gat["level"] = level;
	tp->set_gate(gat);
	name = ob->query_name();
	gat["name"] = name;
	tp->set_gate(gat);
	bodtype = ob->query_body_type();
	gat["bodtype"] = bodtype;
	tp->set_gate(gat);
	race = ob->query_race();
	gat["race"] = race;
	tp->set_gate(gat);
	shorty = ob->query_short();
	gat["shorty"] = shorty;
	tp->set_gate(gat);
	longy = ob->query_long();
	gat["longy"] = longy;
	tp->set_gate(gat);
	++count;
	gat["count"] = count;
	tp->set_gate(gat);
	
	ob->remove();
	ob = new("/wizards/hermes/newmob");
	ob->move(environment(tp));
	write("You tame " + race + "");
	say(this_player()->query_cap_name()+" tames a " + race + "", ob);
	tp->add_sp(-random(100));
	ob->set_owner(this_player());
	return 1;
}	
int abil() 
{
	object tp;
	tp = this_player();
	if (!tp) return 0;
	if (tp->query_subclass() != "ranger" &&
	tp->query_subclass() != "druid") return 0;
	if (tp->query_level() < 5) return 0;
	return 1;
}
