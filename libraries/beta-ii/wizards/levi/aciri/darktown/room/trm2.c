#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("A path to a wall");
    set_long(
      "%^BOLD%^The path to the Wall is paved with some "
      "sort of dull silver tar-like rock.  The giant "
      "%^GREEN%^forest %^RESET%^%^BOLD%^ seems to move "
      "by itself and shadows rush through it.",);
 
    set_items(([
        "shadows" : "They're probably nothing...",
        "path" : "This is a very beautiful path.  The "
             "flowers around it are Midnight Blue in "
             "colour.",
        "forest" : "The forest is green and composed "
             "mainly of Ever Green trees.",
        ]));
    
    set_exits( (["north" : ROOMS "trm3.c",
                 "south"  : ROOMS "trm1.c", ]) );
    
}
