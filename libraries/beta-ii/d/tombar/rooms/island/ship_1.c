#include <std.h>
#include <tombar.h>

inherit ROOM;
int note_found;

void create() {
    ::create();
    set_name("An abandoned ship");
    set_properties(([ "light": 1, "night light": 0, "ship" : 1 ]));
    set_exits(([
		"down" : ROOMS"island/lagoon_7",
		"north" : ROOMS"island/ship_2",
		"stairway" : ROOMS"island/ship_cdeck",
	]));
	set_long("The ship is fairly small perhaps being used at one "
		"time as a merchant ship.  The white sails have long since "
		"torn preventing the ship from sailing.  Several crates "
		"litter the deck.  A small stairway leads up to the captains "
		"deck and the large mast stands in the center of the deck.");
	set_listen("default", "Water can be heard lapping against the "
		"side of the deck.");
	set_smell("default", "The smell of rotting wood lingers.");
	set_items(([ 
		"fish" : "The fish are floating dead in the water.",
		({ "sails", "white sails" }) : "The white sails flap in the "
			"wind.  The sails are riddled with tears and rips.",
  		({ "crate", "crates" }) : "Several crates are sprawled out "
			"across the deck.",
/*
  		({ "crate", "crates" }) : "Several crates are sprawled out "
			"across the deck.  One of the crates has a strange marking "
			"on it.",
*/
	]));

}

void reset() {
	::reset();
	note_found = 0;
}

void init() {
	::init();
//	add_action("search_crate", "search");
	add_action("climb_mast", "climb");
}

int search_crate(string str) {
	if(!str || (str != "crate" && str != "crates")) return 0;

	if(note_found) {
		write("You rumage through the crates but find nothing.");
	}
	write("You rumage through the crate marked with the strange symbol.");
	new(OBJ"note")->move(this_player());
	return 1;
}

int climb_mast(string str) {
	if(!str || str != "mast") return notify_fail("Climb what?\n");

	this_player()->move_player("ship_nest");
	return 1;
}
