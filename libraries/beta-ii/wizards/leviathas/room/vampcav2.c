#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Vampires Cave");
    set_long(
      "%^BOLD%^T%^BLACK%^o the East there is a huge opening leading"
      "into the cave.  The walls get darker and darker.",);
 
    set_items(([
        "walls" : "Pitch black walls.",
        ]));
    
    set_exits( (["north" : ROOMS "vampcav3.c",
                 "east" : ROOMS "vampcav1.c"]) );
    
}
