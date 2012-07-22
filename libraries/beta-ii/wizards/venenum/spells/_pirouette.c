#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_pirouette(string str)
{
    int a,b, i, clear;
    string target_thing;
    object ob;
    object o;
    object *wield, *weapons;
    string skill;
    weapons = ({});
    if (!abil()) {
	return 0;
    }
    if ((!str || str=="") && !this_player()->query_current_attacker())
    {
	write("Who what where?");
	return 1;
    }
    if (environment(this_player())->query_property("no attack"))
    {
	write("Greater powers prevent your malice.");
	return 1;
    }
    if(this_player()->query_rest_type()) {
	return notify_fail("Not while sitting.");
    }
    if(this_player()->query_ghost())
	return notify_fail("You are dead!\n");
    if(!b=sizeof(wield=this_player()->query_wielded())) {
	return notify_fail("You need at least one knife or blunt to spin with.\n");
    }
    i = sizeof(wield);
    while (i--) {
	if(wield[i]->query_type() == "knife" || wield[i]->query_type() == "blunt")
	    weapons  += ({ wield[i] });
    }
    if(!sizeof(weapons)) {
	return notify_fail("You need at least one knife or blunt to spin with.\n");
    }
    b = sizeof(weapons);
    if (this_player()->query_current_attacker()) 
	ob = this_player()->query_current_attacker();
    else {
	ob = present(str, environment(this_player()));
	if (!ob)
	{
	    write("You dont see that.");
	    return 1;
	}
	if (ob==this_player())        {

	    write("You need help, kid.");
	    return 1;
	}
    }
    if (this_player()->query_sp() < 50) 
    {
	write("Neeeeed... more... stamina!");
	return 1;
    }
    if (this_player()->query_disable())
	return notify_fail("You are busy.\n");
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" is too small and tiny for you!");
	return 1;
    }
    this_player()->set_disable();
    if (b > 1)
	if ((this_player()->query_skill("attack")+this_player()->query_skill("entertainment")/1.5) < random(90))
	    b = 1;
    write("You spin about on your toes, a whirling blur of %^BOLD%^%^BLACK%^cold steel death%^RESET%^.");
    message("room", this_player()->query_cap_name()+" spins about on "+this_player()->query_possessive()+" toes, a whirling blur of %^BOLD%^%^BLACK%^cold steel death%^RESET%^.", environment(this_player()), this_player());
    if (!present("pirouette_obj", this_player()))
    {
	o=new("/wizards/venenum/stuff/pirouetteobj.c");
	o->start_stuff();
	o->move(this_player());
    }
    if (random(100) == 7)
    {
	write("%^BOLD%^%^YELLOW%^You feel lucky!%^RESET%^");
	this_player()->add_skill_bonus("knife",this_player()->query_skill("knife")/2,1);
	this_player()->add_skill_bonus("blunt",this_player()->query_skill("blunt")/2,1);
    }

    while(b--) {
	if(b >= 2) {
	    if(random(3) == 0)
		b--;
	    if(random(10) == 0)
		b--;
	}
	// Added to prevent arena deaths
	if(this_player()->query_arena())
	    if(!present(ob->query_name(), environment(this_player())))
		return 1; 
	skill = weapons[b]->query_type();
	if (skill == "knife")
	{
	    a = BALANCE_D->get_damage( this_player(), ob, 2, ({ "attack", skill, skill, skill, "entertainment" }), ({ "strength", "dexterity" })) +weapons[b]->query_wc()*5/3;
	}
	if (skill == "blunt")
	{
	    a = BALANCE_D->get_damage( this_player(), ob, 2, ({ "attack", skill, skill, skill, "entertainment" }), ({ "strength", "dexterity" })) +weapons[b]->query_wc()*5/3;
	}
	a = a / 1.5;
	if (a < 0)
	{
	    write("Your whirling dance is truely pathetic in comparison to this creature.");
	    say( this_player()->query_cap_name()+"'s whirling dance seems to pale before "+ob->query_cap_name()+".");
	    return 1;
	}
	if (skill == "knife")
	{
	    write("Your spinning blades slash into "+ob->query_cap_name()+".");
	    message("info", this_player()->query_cap_name()+" spins about on the spot, slashing "+ob->query_cap_name()+" expertly in "+this_player()->query_possessive()+" furious dance.", environment(this_player()), ({ this_player(), ob}));
	    message("info", this_player()->query_cap_name()+" spins about on the spot, slashing you expertly with "+this_player()->query_possessive()+" blades in a furious dance.", ob);
	}
	if (skill == "blunt")
	{
	    write("Your spinning blungeons bash into "+ob->query_cap_name()+".");
	    message("info", this_player()->query_cap_name()+" spins about on the spot, bashing "+ob->query_cap_name()+" expertly in "+this_player()->query_possessive()+" furious dance.", environment(this_player()), ({ this_player(), ob}));
	    message("info", this_player()->query_cap_name()+" spins about on the spot, bashing you expertly with "+this_player()->query_possessive()+" blundgeons in a furious dance.", ob);
	}
	target_thing = (string)ob->return_target_limb();
	ob->do_damage(target_thing, a);
	this_player()->add_sp(-(a/5));
    }
    return 1;
}

int abil() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_subclass() != "gypsy") return 0;
    if (o->query_level() < 15) return 0;
    if (o->query_skill("knife") > 60 || o->query_skill("blunt") > 60) return 1;
    return 1;
}

void help() {

    write("Syntax: <pirouette [(living)]>\n\n"

      "An attack requiring a fair amount of skill, pirouette allows the gypsy to spin gracefully while attacking the opponent using any wielded knife. While this can lead to an extraordinary amount of damage being done the offensive nature of the dance leaves the gypsy's defense more vulnerable to attack.\n"); 
}

