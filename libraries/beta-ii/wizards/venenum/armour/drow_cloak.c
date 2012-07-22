#include <std.h>
inherit ARMOUR;

int do_wear()
{

    if (this_player()->query_race() == "drow" || this_player()->query_race() == "vampire")
    {
	write("You clip the cloak around your neck.");
	message("say", this_player()->query_cap_name()+" clips a Dark Elven Piwafwi around "+this_player()->query_possessive()+" neck.", environment(this_player()), this_player()); 
	return 1;
    }
    else
    {
	write("The cloak becomes sticky, gooey spiderwebs which fall apart instantly.");
	message("say", this_player()->query_cap_name()+" attempts to don a Dark Elven Piwafwi but it turns to a gooey mess of spiderwebs.", environment(this_player()), this_player());
	this_object()->move("/d/nopk/standard/void.c");
	return 0;
    }

}

void create() {
    ::create();
    set_name("piwafwi");
    set("id", ({"piwafwi", "cloak"}) );
    set_short("Dark Elven Piwafwi");
    set_type("cloak");
    set_long("This billowing cloak appears to be crafted from pure spiderwebs, but feels as smooth as silk. The spiderwebs are actually tiny links of chainmail, strung together to strengthen the cloak and form an artistic pattern on the back. This cloak provides greater protection then regular cloaks and is augmented by an array of magical spells placed upon it. A thick cloth hood protects the head both from incoming blows and the sun's blinding light.");
    set_limbs( ({"right leg", "left leg", "torso", "head"}) );
    set_mass(19);
    set_value(100);
    set_ac(5);
    set_wear((: do_wear :));
}

int query_auto_load() {
    if(this_player()->query_race() == "drow")
	return 1;
}
