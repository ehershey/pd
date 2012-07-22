#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Vampires Cave");
    set_long(
      "%^BLUE%^T%^BOLD%^he fog has passed and the light can be "
      "seen now, however it appears differently.  Instead of white "
      "it is blue.  The fog must have tinted it.  There is a portal-"
      "like doorway to the west.",);
 
    set_items(([
        "fog" : "It is to the south.  It tinted the light. ", 
        "light" : "It is a light blue.",
        "doorway" : "Who knows where it leads?"
       
        ]));
    
    set_exits( (["doorway" : ROOMS "vampcav10.c",
                 "south" : ROOMS "vampcav8.c", ]) );
    
        
}
