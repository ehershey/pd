#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
                "no teleport" : 1]) );
   set_short("Inside a mage tower");
   set_long(
            "Dark stone walls stretch high into the tower. A "
            "spiraling staircase winds up several flights. A painting "
            "of a dwarf wearing a magicians cap and a beard as white "
            "as snow is hung. An open doorway leads back out to Copper "
            "Street. Two potted ferns stand next to the staircase, one "
            "on each side of the steps.");
   set_items(([
            "staircase" : "A spiraling staircase leads up to the top "
                        "of the tower.",
            "walls" : "%^BOLD%^%^BLACK%^Dark stone walls stretch high "
		 "into the tower.",
            "painting" : "A painting of a dwarf wearing a magicians "
                 "cap and a beard as white as snow is hung. A small "
		 "etching on the frame of the painting reads: Andorf",
            "doorway" : "An open doorway leads back out. ",
            "stairs" : "The stairs twist and turn up and down the tower.",
            "ferns" : "Two potted ferns stand next to the staircase, one "
		 "on each side."
   ]));
   set_smell("default", "It almost smells like burnt hair.");
   set_listen("default", "The crackling of energy is strong here.");
   set_exits( ([ 
        "out" :  ROOMS "towerent",
        "northeast" :  ROOMS "tower1_2"]));
}
void reset() {
::reset();
    if(!present("creeper")) new(MOB"shadowcreeper.c")->move(this_object());
    if(!present("creeper 2")) new(MOB"shadowcreeper.c")->move(this_object());
}
