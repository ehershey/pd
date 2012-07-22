#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
      
      "This is an elephant's graveyard.  There are sounds of sick elephants "
      "and looking around there are bones scattered everywhere."
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
"north" : ROOMS "mar3",
"northeast" : ROOMS "mar4",
"east" : ELE "ele24",
"south" : ELE "ele18",
"southeast" : ELE "ele19",
"southwest" : ELE "ele17",
"northwest" : ROOMS "mar2",
"west" : ELE "ele22",
    ]) );
}
