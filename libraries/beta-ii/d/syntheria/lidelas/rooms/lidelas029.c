#include <std.h>
#include <lidelas.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("grassy patch");
        set_short("Grassy patch");
        set_long("A simple patch of grass in the middle of a town almost completely made of stone, bronze, and copper. There are a few wild flowers that grow here, but other then the grass, no other plant life lives here. To the west is the east side of a large church, it has many large windows with beautiful scenes in them. On every ledge there is a small statue of an angel, and on every wall, an angel has been carved into it. The church has many towers that reach into the sky, and on top of each tower is a statue.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"flowers"  :   "A common wildflower",
	    ]));
	    set_listen("default", "The sounds of chanting echo from the church.");
	    set_smell("default", "The sweet smell of pollen fills the air.");
	    set_exits(([
			"south"		: ROOMS "lidelas028.c",
        ]));
}



