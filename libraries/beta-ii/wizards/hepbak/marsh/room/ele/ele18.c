#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
      "This is The heart of the graveyard. Bones are scattered "
      "everywhere and sickly elephants begging for death."
    );
    set_night_long(
      "There are sharp bones scattered everywhere.  This is the beginning "
      "of an Elephant's Graveyard.  It is a very drab and dreay place to "
      "be."
    );
    set_items(([
        "bones" : "They are of all different sizes from mostly elephants.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"north" : ELE "ele23",
"northeast" : ELE "ele24",
"east" : ELE "ele19",
"south" : ELE "ele12",
"southeast" : ELE "ele13",
"southwest" : ELE "ele11",
"northwest" : ELE "ele22",
"west" : ELE "ele17",
    ]) );
}
