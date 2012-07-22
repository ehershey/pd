#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("rafore street");
        set_short("Rafore Street");
        set_long("Rafore Street runs through the center of Lidelas, it runs north and south. The street is made up of large cobble stones, finely polished. The street is very wide, it looks like it was designed to allow a large amount of traffic to freely move about. The intersection of Rafore Street and Eni avenue is here, Eni avenue goes off to the east, while Rafore Street goes to the south. On each side of the street, large buildings have been built. Every building is at least four stories high, there looks to be a series of arches above every window. The arches lead up to tall points. Each level of the buildings has a small ledge from which many small stone gargoyles are carved into the ledges. To the north is a forbidding looking forest, it is very dark and thick.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"gargoyles"    :  "They are not very large, and seem to be carved into the building."
	    ]));
	    set_listen("default", "The sound of carts moving on the stone steets can be heard in all directions.");
	    set_smell("default", "The odor of horse manure fills the air.");
	    set_exits(([
			"north"		: ROOMS "lidelasForest002.c",
			"south"		: ROOMS "lidelas027.c",
            "east"		: ROOMS "lidelas025.c",
        ]));
        add_pre_exit_function("north", "go_north");
}

int go_north() {
  if(!this_player()->is_player()) return 0;
  return 1;
}

