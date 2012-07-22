#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Vampires Cave");
    set_long(
      "%^BOLD%^Y%^BLACK%^et another room of darkness.  Now the "
      "%^RED%^red %^BLACK%^colour is growing more and more and "
      "seems to be reflecting off of something to the north.",);
 
    set_items(([
        "red" : "%^RED%^Blood is spilt all over the floor.",
        ]));
    
    set_exits( (["north" : ROOMS "vampcav5.c",
                 "south" : ROOMS "vampcav3.c"]) );
    
}
