#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Vampires Cave");
    set_long(
      "%^CYAN%^The fog is everywhere.  The light still shines from "
      "the north.",);
 
    set_items(([
        "light" : "A beautiful, quiet light. ", 
        ]));
    
    set_exits( (["north" : ROOMS "vampcav9.c",
                 "south" : ROOMS "vampcav7.c", ]) );
    
        
}
