#include <std.h>
inherit ARMOUR;

int do_wear()
{

    if (this_player()->query_race() == "drow" || this_player()->query_race() == "vampire")
    {
	write("You buckle the Dark Elven shield to your arm.");
	message("say", this_player()->query_cap_name()+" buckles a Dark Elven shield to "+this_player()->query_possessive()+" arm.", environment(this_player()), this_player()); 
	return 1;
    }
    else
    {
	write("The shield collapses into smoke as you try to buckle it on.");
	message("say", this_player()->query_cap_name()+" buckles on a Dark Elven shield, but it instantly turns to smoke.", environment(this_player()), this_player());
	this_object()->move("/d/nopk/standard/void.c");
	return 0;
    }

}

void create() {
    ::create();
    set_name("shield");
    set("id", ({"shield"}) );
    set_short("Dark Elven Shield");
    set_type("shield");
    set_long("This round, medium shield serves as the standard shield for the dark-dwelling Drow. A dull black with the symbol of a white spider blazed on the front, it functions both as a battle tool and a display of the Dark Elf loyalty to the spiderqueen, Lloth. It on it's own is sturdy enough, but this particular one has been enchanted to increase it's protective value even more.");
    set_limbs( ({"torso", "left hand", "left arm"}) );
    set_mass(17);
    set_value(90);
    set_ac(8);
    set_wear((: do_wear :));
}

int query_auto_load() {
    if(this_player()->query_race() == "drow")
	return 1;
}
