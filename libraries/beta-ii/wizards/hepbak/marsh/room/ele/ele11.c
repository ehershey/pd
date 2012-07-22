#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
      "The Heart of the graveyard.  Nothing but dying elephants. "
       );
    set_night_long(
       "The Heart of the graveyard.  Nothing but dying elephants. "
    );
    set_items(([
        "bones" : "They are of all different sizes from mostly elephants.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"north" : ELE "ele17",
"northeast" : ELE "ele18",
"east" : ELE "ele12",
"south" : ELE "ele7",
"southeast" : ELE "ele8",
"west" : ELE "ele10",
"northwest" : ELE "ele16",
    ]) );
}
