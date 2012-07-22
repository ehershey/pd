#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
      "This is an elephant's graveyard.  There are bones scattered "
      "everywhere and there are sounds of sickly elephants coming from the
south"
    );
    set_night_long(
      "There are sharp bones scattered everywhere.  This is the beginning "
      "of an Elephant's Graveyard.  It is a very drab and dreary place to "
      "be."
    );
    set_items(([
        "bones" : "They are of all different sizes from mostly elephants.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"west" : ELE "ele19",
"northwest" : ELE "ele24",
"north" : ELE "ele25",
"southwest" : ELE "ele13",
"south" : ELE "ele14",
    ]) );
}
