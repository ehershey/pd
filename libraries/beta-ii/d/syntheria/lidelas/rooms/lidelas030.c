#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("feng avenue");
        set_short("Feng avenue");
        set_long("Feng avenue bisects Lidelas, splitting the town into the north and south ends. Feng avenue runs from the far west end of town, to the far east side of town. The avenue is made of very fine cobble stone, each stone looks almost new. Many large buildings line the street, the common theme between them all is that every one of them has ornate sculptures of gargoyles at points all over the buildings. All of the gargoyles seem to have been made to face the street, so that they may look onto anyone who passes by. Every building has many arched windows, above every window is a sharp point that eventually leads to a sharp tower. To the north is a large church, enormous glass windows dominate the front of the building. Large bells hang from the very top of the church. To the south sits a gigantic building with large wooden doors. A large amount of noise comes from the building, a large number of people must be in there. Two large torches sit just in front of the building.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"gargoyles"    :  "They are not very large, and seem to be carved into the building.",
    	"torches"      :  "Large torches that burn brightly."
	    ]));
	    set_listen("default", "The sound of carts moving on the stone steets can be heard in all directions.");
	    set_smell("default", "The odor of horse manure fills the air.");
	    set_exits(([
			"east"		: ROOMS "lidelas028.c",
			"west"		: ROOMS "lidelas033.c",
		    "north"		: ROOMS "lidelas031.c",
			"south"		: ROOMS "lidelas032.c",
        ]));
        add_pre_exit_function("north", "go_north");
        add_pre_exit_function("south", "go_south");
}

int go_north() {
  if(!this_player()->is_player()) return 0;
  return 1;
}

int go_south() {
  if(!this_player()->is_player()) return 0;
  return 1;
}




