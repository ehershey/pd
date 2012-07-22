#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountains" : 1, "town" : 1]) );
   set_short("Steel Hammer Village gates");
   set_long(
            "The path leads west to the mountains and east into "
            "a village. Large, iron gates connect into the "
            "mountain to create an impenetrable enterance. "
            "A large sign hangs above the gate. Small stone "
            "buildings can be seen through the gate as well as "
	    "dwarves hustling and bustling around the village.");
   set_items(([
            "mountains" : "The mountains stretch in all directions. The "
                        "mountain walls dictate where the path leads. ",
            "sign" : "A large sign above the gates reads: Steel Hammer "
                "Village. ",
            "buildings" : "Small, dwarf sized buildings can be seen through "
                "the gate.",
            "dwarves" : "Dwarves are seen through the gate running all "
                "around the village, taking part in their daily activities.",
            "path" : "A dirt path leads west into the mountains "
		 	"and east into the village. ",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occasionally a twig can be heard snapping from afar.");
   set_exits( ([ 
        "west" :  ROOMS "86",
        "east" :  ROOMS "sh_2"]));
}
void reset() {
::reset();
    if(!present("gates")) new(ITEMS"gates.c")->move(this_object());
    if(!present("guard")) new(MOB"gateguard.c")->move(this_object());
    if(!present("guard 2")) new(MOB"gateguard.c")->move(this_object());
}

