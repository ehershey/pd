#include <std.h>
#include <aciri.h>
inherit ROOM;

void create() {
::create();
    set_short("An Archmage's home");
    
    set_listen("default", "%^BOLD%^%^RED%^The crackling of a fire can be heard.%^RESET%^");
    set_long("This is just a bare corner of the room.  From here, it looks pretty nice.  A fireplace to "
         "the west, an alchemist's center to the south and the entrance with a beautiful carpet southwest. ");
    
    
    set_items(([
          "fireplace" : "The fireplace burns brightly.",
          "fire" : "The fire flickers madly.",
          
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
        "indoors" : 1,
        "town" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "fortofaciri66.c",
        "south" : ROOMS "fortofaciri69.c",
        "southwest" : ROOMS "fortofaciri68.c",
       ]));
       
}

