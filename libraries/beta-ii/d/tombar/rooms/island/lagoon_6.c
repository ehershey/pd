#include <std.h>
#include <tombar.h>

inherit ROOM;
int open;

void create() {
    ::create();
    set_name("Tombar Lagoon");
    set_properties(([ "light": 1, "night light": 0 ]));
    set_exits(([
		"southwest" : ROOMS"island/lagoon_5",
		"northeast" : ROOMS"island/lagoon_7",
	]));
	set_long("The path curves here following the edge of the water.  Scum "
		"and algea line the side of the water.  Small fish are seen in the "
		"water belly up floating with the waves of the ocean.  The ship "
		"appears larger the closer you come to it.");
	set_listen("default", "Flying bugs create a small buzzing sound.");
	set_smell("default", "The smell of death and decay lingers.");
	set_items(([ 
		"fish" : "The fish are floating dead in the water.",
		"ship" : "The ship can be seen at the other side of the lagoon "
			"rocking in the waves.  It's black sails blow in the wind.",
	]));

}

