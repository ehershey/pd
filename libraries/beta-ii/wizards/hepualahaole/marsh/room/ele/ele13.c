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
      "everywhere and to the south, sickly elephants are jumping the cliff to
end it all."
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
"northeast" : ELE "ele20",
"west" : ELE "ele12",
"northwest" : ELE "ele18",
"north" : ELE "ele19",
"southwest" : ELE "ele8",
    ]) );
}
