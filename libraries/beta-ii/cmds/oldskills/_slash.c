#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_slash(string str)
{
    int a,b, i, *clear;
    string target_thing;
    object ob;
    object *wield;
    if (!abil()) {
	write("What?\n");
	return 1;
    }
    if ((!str || str=="") && !this_player()->query_current_attacker())
    {
	write("Slash what?");
	return 1;
    }
    if (environment(this_player())->query_property("no attack"))
    {
	write("Greater powers prevent your malice.");
	return 1;
    }
    if(this_player()->query_rest_type()) {
	write("You are not in a position to slash!");
	return 1;
    }
    if(!b=sizeof(wield=(object *)this_player()->query_wielded())) {
	notify_fail("You need a weapon to slash with!\n");
	return 0;
    }
    i = sizeof(wield);
    clear = ({});
    while(i--)
	clear += ({0});
    i = sizeof(wield);
    while (i--) {
	if (wield[i]->query_type() == "blade" || wield[i]->query_type() == "knife"
	  || wield[i]->query_type() == "axe")
	    clear[i] = 1;
    }
    i = sizeof(wield);
    if (!(member_array(1, clear)+1))
	return notify_fail("You need a bladed weapon to slash with!\n");
    if (this_player()->query_current_attacker()) 
	ob = this_player()->query_current_attacker();
    else {
	ob = present(str, environment(this_player()));
	if (!ob)
	{
	    write("You dont see that.");
	    return 1;
	}
	if (ob==this_player())
	{
	    write("Something must be wrong with you.");
	    return 1;
	}
    }
    if (this_player()->query_sp() < 20) 
    {
	write("You are too tired to slash.");
	return 1;
    }
    if(this_player()->query_disable()) return 1;
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    this_player()->set_disable();
    if (b > 1)
	if (this_player()->query_skill("attack") < random(80))
	    b = 1;
    while(i--) {
	if(b > 2) {
	    if(random(3) == 0)
		b--;
	    if(random(10) == 0)
		b--;
	}
	if(!clear[i]) continue;
	if(b < 1) continue;
	b--;
	if(this_player()->query_arena())
	    if(!present(ob->query_name(), environment(this_player())))
		return 1; 
	a = this_player()->query_skill("attack") -
	ob->query_skill("defense")/2 +
	this_player()->query_stats("strength")*5/2 +
	this_player()->query_stats("dexterity")*5/3 -
	ob->query_stats("dexterity")*2/3 +
	wield[i]->query_wc()*5/3;
	if (a < 10)
	{
	    write("You miss your slash.");
	    say( this_player()->query_cap_name()+" misses "+possessive(this_player())+" slash.");
	    return 1;
	}
	write("You slash "+ob->query_cap_name()+" with your "+wield[i]->query_cap_name()+".");
	message("info", this_player()->query_cap_name()+" slashes "+ob->query_cap_name()+".", environment(this_player()), ({ this_player(), ob }));        
	message("info", this_player()->query_cap_name()+" slashes you.", ob);
	target_thing = (string)ob->return_target_limb();
ob->do_damage(target_thing, a*2/5);
	ob->check_on_limb(target_thing);
	this_player()->add_sp(-(a/7));
    }
    return 1;
}
int abil() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_class() != "fighter") return 0;
    if (o->query_level() < 5) return 0;
    if (o->query_skill("blade") < 15) return 0;
    return 1;
}
void help() {
    write("Syntax: <slash [(living)]>\n\n"
      "A fighter command which enables you to use your sword(s) to slash powerfully at your oponent. If you are wielding more than one sword you have the ability to slash more than once.\n"); }