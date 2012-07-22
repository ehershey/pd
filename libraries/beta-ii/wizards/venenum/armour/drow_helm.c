#include <std.h>
inherit ARMOUR;

int do_wear()
{

    if (this_player()->query_race() == "drow" || this_player()->query_race() == "vampire")
    {
	write("You place the helm on head and buckle the strap.");
	message("say", this_player()->query_cap_name()+" places a Dark Elven helm over "+this_player()->query_possessive()+" head and buckles the strap.", environment(this_player()), this_player()); 
	return 1;
    }
    else
    {
	write("The helm disintergrates into dust, blowing away with the wind.");
	message("say", this_player()->query_cap_name()+" touches a Dark Elven helm but it disintergrates instantly.", environment(this_player()), this_player());
	this_object()->move("/d/nopk/standard/void.c");
	return 0;
    }

}

void create() {
    ::create();
    set_name("helm");
    set("id", ({"helm"}) );
    set_short("Dark Elven Helm");
    set_type("helmet");
    set_long("Crafted from an unknown metal and blackened with charcoal, this helm forms the standard armour of the Dark Elf invasion forces. Consisting of a shaped bowl for the head with metal flaps hanging down to protect the cheeks and the back of the head, this helm provides good all-around protection. To increase it's defensive functionality, this helm has been enchanted with a number of protective spells.");
    set_limbs( ({"head"}) );
    set_mass(6);
    set_value(90);
    set_ac(5);
    set_wear((: do_wear :));
}

int query_auto_load() {
    if(this_player()->query_race() == "drow")
	return 1;
}
