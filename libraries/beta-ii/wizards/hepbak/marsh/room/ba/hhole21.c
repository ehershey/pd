#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Uwagi's Homes");
    set_long(
       "This room is empty, there is a for sale sign hanging on the back wall. "
  
    );
    set_items(([
        "room" : "It is up for sale",
        "sign" : "It's a scrap of wood, and has a hand painted %^BOLD%^%^RED%^For Sale%^RESET%^ on it.",
        "wall" : "There's a sign hanging on it.",
        "wood" : "It's a left over scrap of wood from the construction site.",
    ]));
    set_exits( ([
"west" : BA "hhole15",
    ]) );

}
