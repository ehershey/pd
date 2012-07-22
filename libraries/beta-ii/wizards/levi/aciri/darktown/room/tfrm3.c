#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Lost Library of Terra");
    set_long(
      "%^BOLD%^The inside wood of the massive Willow Tree "
      "is Silver. Uneven Steps lead deep down underground.");
 
    set_items(([
        "stairs" : "They are beautiful, but hastily made. "
             "It would appear that very few feet have used "
             "these steps.",
        "steps" : "One of the steps is missing, creating a "
             "hole that you'll have to hop over to get down "
             "any further.",
        "hole" : "A faint light flickers from in it...",        
    ]));
    
    set_exits( (["out" : ROOMS "tfrm2.c", 
                 "down" : ROOMS "tfrm4.c", 
                 "hole" : ROOMS "vampslay1.c", ]) );
    add_invis_exit("hole");
    
    
}
