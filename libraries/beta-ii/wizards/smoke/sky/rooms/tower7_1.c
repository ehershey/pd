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
            "spiraling staircase only leads down for several flights. A "
            "handrail twists with the staircase. An open doorway leads "
            "north and the only window of the entire tower points south.");
   set_items(([
            "staircase" : "A spiraling staircase leads to the bottom "
                        "of the tower.",
            "walls" : "%^BOLD%^%^BLACK%^Dark stone walls stretch high "
		 "into the tower.",
	   "window" : "A window points south out of the mage tower. All "
		 "that can be seen through the window is the side "
		 "of a mountain.",
            "handrail" : "The wooden handrail twists and turns with "
                 "the staircase. ",
            "light" : "A %^BOLD%^%^CYAN%^glowing blue light%^RESET%^ comes "
		 "from the north."
   ]));
   set_smell("default", "It almost smells like burnt hair.");
   set_listen("default", "The crackling of energy is strong here.");
   set_exits( ([ 
        "northwest" :  ROOMS "tower6_4",
        "north" :  ROOMS "tower_mage"]));
}
void reset() {
::reset();
    if(!present("gargoyle")) new(MOB"gargoyle3.c")->move(this_object());
    if(!present("gargoyle 2")) new(MOB"gargoyle3.c")->move(this_object());
}
