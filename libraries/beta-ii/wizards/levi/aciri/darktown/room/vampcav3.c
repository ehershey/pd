#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Vampires Cave");
    set_long(
      "%^BOLD%^T%^BLACK%^he cave keeps getting darker and darker."
      "Faint screams can be heard from far, far off.  There is "
      "something %^RED%^red %^BLACK%^on the floor.",);
 
    set_items(([
        "red" : "%^RED%^Blood is spilt all over the floor.",
        ]));
    
    set_exits( (["north" : ROOMS "vampcav4.c",
                 "south" : ROOMS "vampcav2.c"]) );
    
}
