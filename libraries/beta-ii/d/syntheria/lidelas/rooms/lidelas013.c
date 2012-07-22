#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("feng avenue");
        set_short("Feng avenue");
        set_long("Feng avenue bisects Lidelas, splitting the town into the north and south ends. Feng avenue runs from the far west end of town, to the far east side of town. The avenue is made of very fine cobble stone, each stone looks almost new. Many large buildings line the street, the common theme between them all is that every one of them has ornate sculptures of gargoyles at points all over the buildings. All of the gargoyles seem to have been made to face the street, so that they may look onto anyone who passes by. Every building has many arched windows, above every window is a sharp point that eventually leads to a sharp tower.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"gargoyles"    :  "They are not very large, and seem to be carved into the building."
	    ]));
	    set_listen("default", "The sound of carts moving on the stone steets can be heard in all directions.");
	    set_smell("default", "The odor of horse manure fills the air.");
	    set_exits(([
			"east"		: ROOMS "lidelas014.c",
			"west"		: ROOMS "lidelas012.c",
        ]));
}



