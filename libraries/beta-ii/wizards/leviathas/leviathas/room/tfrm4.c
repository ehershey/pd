#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Lost Library of Terra");
    set_long(
      "%^BOLD%^The steps descend deeper and deeper, whispers "
      "start up and seem to grow with every step down you "
      "take.  Perhaps it would be wise to leave.");
 
    set_items(([
        "steps" : "They are beautiful, but hastily made.  It "
            "would appear that very few feet have used these "
            "steps.",                         
    ]));
    
    set_exits( (["up" : ROOMS "tfrm3.c", 
                 "down" : ROOMS "tfrm5.c", ]) );

}

