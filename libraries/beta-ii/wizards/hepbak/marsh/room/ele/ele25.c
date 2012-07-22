#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
      "This is the elephant's graveyard.  There are sounds of sick elephants "
      "everywhere and looking around, bones show evidence that there is no "
      "way that these elephants are making it back alive."
    );
     set_night_long(
      "Elephant's Graveyard, a very drab and dreary place to be."
    );
    set_items(([
        "bones" : "They are of all different sizes from mostly elephants.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"west" : ELE "ele24",
"northwest" : ROOMS "mar4",
"north" : ROOMS "mar5",
"southwest" : ELE "ele19",
"south" : ELE "ele20",
    ]) );
}
