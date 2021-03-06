#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 1, "town" : 1]));
     set_name("Rhondale Outer Circle");
     set_short("Rhondale Outer Circle");
     set_day_long("Rhondale is heavily fortified against the dangerous inhabitants of the forest. The outer path circles the entire village just inside the walls. The cobblestones underfoot are smooth though not at all slippery. Here the northwest lookout tower stretches up from the wall.");
     set_night_long("The outer path of Rhondale leads a circle all around the city just inside the main walls. Torches are placed every fifteen meters eliminating the shadows of night.  The cobblestones are worn smooth by the various night patrols. The northwest lookout tower makes a huge shadow in the night.");
     set_exits(([
		"northeast"	: KEEPROOM"zvillage/outer1100.c",
		"southwest"	: KEEPROOM"zvillage/outer1000.c",
                "up"            : KEEPROOM"zvillage/nwtower.c"
                ]));
}
