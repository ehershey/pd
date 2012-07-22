// a dungeonware.net producion 28-Nov-00
// based upon firebomb.c
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_psistorm(string str)
{
    string party;
    int i, x;
    object *per=({});
    if(str) return 0;
    if (!spell()) {
	return 0;
    }
    if (this_player()->query_mp() < 170)
	return notify_fail("Your spell fails, due to lack of magic.\n");
    if (environment(this_player())->query_property("no attack") || environment(this_player())->query_property("no magic") )
    {
	write("Greater powers prevent your malice.");
	return 1;
    }

    if (this_player()->query_busy())
	return notify_fail("You are busy.\n");

    this_player()->set_magic_round();
    write("%^BOLD%^%^BLUE%^You concentrate on the area calling objects into the air!");
    say("%^BOLD%^%^BLUE%^Objects around "+this_player()->query_cap_name()+" begin to rise up in the air"
      " and fly around the area!");
    this_player()->add_mp(-(random(50)));
    per = all_inventory(environment(this_player()));
    x = sizeof(per);
    if (this_player()->query_party())
	party = this_player()->query_party();
    else party = "AdkIl898-FL00Jn-neInfe_ron";
    while(x--) {
	if (!per[x]->is_living()) continue;
	if (this_player()->query_mp() < 150) {
	    write ("%^BOLD%^%^BLUE%^The objects fall back to the ground.%^RESET%^");
	    break;
	}
	if (per[x]->query_party() == party) continue;
      i =  BALANCE_D->get_damage( this_player(), per[x], 3, ({ "psionics", "psionics", "magic attack" }),
                                   ({ "intelligence", "intelligence", "wisdom" }), ({ "intelligence", "wisdom" }) );
        i = i*4/5;
	if (!per[x]->query_ghost() && per[x] != this_player() &&
	  per[x]->query_level() > 5 && !wizardp(per[x])) {
	    if(5 > i) {
		write("%^BOLD%^%^BLUE%^Your objects bounce off "+per[x]->query_cap_name()+" doing no harm!%^RESET%^");
		say("%^BOLD%^%^BLUE%^Objects bounce off "+per[x]->query_cap_name()+" doing no harm!%^RESET%^");
		tell_object(per[x], "%^BOLD%^%^BLUE%^Objects bounce off of you doing no harm!");
		continue;
	    }
	    this_player()->set_paralyzed(random(2)+1, "You are concentrating on moving the objects.");
	    if(!this_player()->kill_ob(per[x])) {
		write(per[x]->query_cap_name()+" can't be attacked by you yet.");
		return 1;
	    }
	    if (environment(this_player()) != environment(per[x])){
		write("%^BOLD%^"+per[x]->query_cap_name()+" is not here.%^RESET%^");
		tell_room(environment(this_player()), "%^BOLD%^%^BLUE%^The objects fall back to the ground.%^RESET%^", ({ this_player() }));
		return 1;
	    }
	    if (!per[x]){
		write("%^BOLD%^"+per[x]->query_cap_name()+" is not here.%^RESET%^");
		tell_room(environment(this_player()), "%^BOLD%^%^BLUE%^The objects fall back to the ground.%^RESET%^", ({ this_player() }));
		return 1;
	    }
	    per[x]->damage(i);
	    tell_object(per[x], "%^BOLD%^%^BLUE%^You are pelted by objects flying around!");
	    tell_room(environment(per[x]), "%^BOLD%^%^BLUE%^"+per[x]->query_cap_name()+
	      " is pelted by the objects flying around!", ({ per[x] }));
        this_player()->add_mp(-i/7);
	    this_player()->set_disable();
	}
    }
    return 1;
}
int spell()
{
    if (this_player()->query_subclass()!="sorceror") return 0;
    if (this_player()->query_level() < 30) return 0;
    if (this_player()->query_skill("psionics") < 150) return 0;
    return 1;
}
void help()
{
    write("Syntax: <psistorm>\n"
      "High level sorcerors release their powers on all the objects around, "
      "lifting them up and throwing them around the area at a high rate of speed. \n"
      "%^BOLD%^%^RED%^WARNING%^RESET%^: This spell will attack everything in the room.");
}