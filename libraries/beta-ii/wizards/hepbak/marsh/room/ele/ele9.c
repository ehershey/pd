#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
      "This is still part of the elephant's graveyard.  Bones are scattered "
      "high on either side, making a path go north and south."
    );
    set_night_long(
      "This part of the graveyard is quiet.  There are bones piled up high "
      "on either side, making the path go north and south. "
      "be."
    );
    set_items(([
        "bones" : "They are of all different sizes from mostly elephants.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"north" : ELE "ele14",
"south" : ELE "ele6",
    ]) );
}
