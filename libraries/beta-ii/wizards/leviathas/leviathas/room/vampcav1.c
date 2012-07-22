#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Vampires Cave");
    set_long(
      "%^BOLD%^%^BLACK%^The walls of the enterance to the Cavern "
      "are Jet-Black.  There is a massive hole west of here that "
      "leads into the massive cave.  Few have taken this path and "
      "lived.",);
 
    set_items(([
        "enterance" : "It is dark and you hear eccos as you approach it.",
        ]));
    
    set_exits( (["west" : ROOMS "vampcav2.c"]) );
    
}
