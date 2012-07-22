#include <std.h>
inherit ARMOUR;

int do_wear()
{

    if (this_player()->query_race() == "drow" || this_player()->query_race() == "vampire")
    {
	write("You slip the soft tunic over your head.");
	message("say", this_player()->query_cap_name()+" slips a Dark Elven tunic over "+this_player()->query_possessive()+" head.", environment(this_player()), this_player()); 
	return 1;
    }
    else
    {
	write("The tunic instantly unravels, turning into useless strands of cloth.");
	message("say", this_player()->query_cap_name()+" prepares to don a Dark Elven tunic, but it unravels into a bundle of useless thread.", environment(this_player()), this_player());
	this_object()->move("/d/nopk/standard/void.c");
	return 0;
    }

}

void create() {
    ::create();
    set_name("tunic");
    set("id", ({"tunic"}) );
    set_short("Dark Elven Invasion Tunic");
    set_type("tunic");
    set_long("This stylish cloth tunic would appear to be no different then many others which adorn the chests of fighters realm-wide, except that this is the tunic of the fabled Dark Elves. Blackest of black cloth, with a white spider symbol blazen acros the chest, this cloth is worn by most Drow to serve as armour and to display any special status they may have achieved. This particular one carries a red stripe down the abdomen of the spider, signalling the wearer it was crafted for is part of a surface invasion or raiding party.");
    set_limbs( ({"torso"}) );
    set_mass(9);
    set_value(40);
    set_ac(1);
    set_wear((: do_wear :));
}

int query_auto_load() {
    if(this_player()->query_race() == "drow")
	return 1;
}
