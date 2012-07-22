// The new monster type
// By Hermes
#include <std.h>
inherit MONSTER;
string name, level, bodtype, race, shorty, longy;
static string owner;
static object ob, pl;
mapping gat = this_player()->query_gate();
int count = gat["count"];
void create() 
{
    ::create();
    ob = this_object();

    set_property("no_tame", 1);
    name = gat["name"];
    set_name(name);
    set_gender("male");
    shorty = gat["shorty"];
    set_short(shorty);
    set("aggressive", 0);
    set_heart_beat(1);
    level = gat["level"];	 
    set_level(level);
    bodtype = gat["bodtype"];	 
    set_long("This used to be a wild animal, now it follows the comands of its owner.");
    set_body_type(bodtype);
    set_alignment(0);
    race = gat["race"];
    set("race", race);
    set_id( ({ race, name }) );
    set_exp(1);

}
void init() 
{
    ::init();
    add_action("command", "command");
}
int command(string str) 
{
    string order, tm;
    object oi;
    int x;
    if ((string)this_player() != owner) return 0;
    if (!str || sscanf(str, "%s to %s", tm, order)!=2) 
    {
	write("Syntax: <command [monster] to [command]>\n");
	return 0;
    }
    oi = present(tm, environment(this_player()));
    if (oi != this_object()) 
	return 0;
    if (order == "reveal powers") 
    {
	ob->force_me("say I have the following special abilities:");
	ob->force_me("say   <reveal powers> and <return>");
	ob->force_me("say I am level " + ob->query_level() + "");
	return 1;
    }
    if (order == "die" || order == "suicide" || order == "return") 
    {
	tell_room(environment(ob), "The animal goes back to his natural habitat.\n",({ ob }));
	count = gat["count"];
	ob->remove();
	--count;
	gat["count"] = count;
	this_player()->set_gate(gat);
	return 1;
    }
    if (order == "kill monster")
    {
	count = gat["count"];
	++count;
	ob->force_me("kill monster " + count);
    }
    else
	ob->force_me(order);
    return 1;
}
void set_owner(string str) 
{
    owner = str;
    pl = present(str, environment(this_object()));
    set_exp_share(pl, to_float(1/2));
}
void heart_beat() 
{
    ::heart_beat();
    if (owner == "blah") 
	return;
    if (this_object() && pl)
	if (environment(this_object()) != environment(pl)) 
	{
	    message("info", "A " + ob->query_race() + " leaves, faithfully following it's owner.\n",
	      environment(ob));
	    this_object()->move(environment(pl));
	    message("info", "A " + ob->query_race() + " enters, faithfully following it's owner.\n",
	      environment((object)owner));
	}
}
int die()
{
    message("info", "The " + ob->query_name() + " runs away, the instict for survival overriding the taming.\n",environment(ob));
    count = gat["count"];
    --count;
    gat["count"] = count;
    this_player()->set_gate(gat);
    ob->remove();
    return 1;
}
int dest()
{
    message("info", ob->query_name() + " goes POOF!\n",environment(ob));
    count = gat["count"];
    --count;
    gat["count"] = count;
    this_player()->set_gate(gat);
    ob->remove();
    return 1;
}	
int quit()
{
    message("info", ob->query_name() + " goes POOF!\n",environment(ob));
    count = gat["count"];
    --count;
    gat["count"] = count;
    this_player()->set_gate(gat);
    ob->remove();
    return 1;
}
object query_owner() { return pl; }
