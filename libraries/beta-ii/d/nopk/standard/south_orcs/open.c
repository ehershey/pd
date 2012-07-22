#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 2);
    set_property("no castle", 1);
    set("short", "An open courtyard in the orc fortress");
    set("long",
        "The courtyard around you is surrounded by ancient stone walls "
        "that gives this fortress the feeling of impregnability.  An "
        "impressive archway south opens out into Orc Valley.  "
        "There are passages east and west.");
    set_items(
        (["courtyard" : "An open yard walled in by stone walls on every side.",
	  "yard" : "It has no roof, but the walls are so high you "
	    "can see only sky.",
	  "fortress" : "It looks extremely old.",
	  "arch" : "A huge, heavily guarded entrance to the fortress.",
	  "archway" : "It forms the huge, heavily guarded entrance to "
	    "the fortress."]) );
    set_exits( 
	      (["east" : ROOMS"south_orcs/passage1",
            "west" : ROOMS"south_orcs/passage2",
              "south" : ROOMS"south_orcs/path1.c",
          "north" : ROOMS"orc_valley/s_guard"]) );
}
