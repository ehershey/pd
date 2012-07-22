#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
      "The graveyard ends here at a very steap cliff.  There is no way "
      "of going down right now, but looking down you see bones smashed "
    );
      "against the rocks.  Seems this is the elephant's suicide cliff."
    set_night_long(
      "The graveyard ends here at a very steap cliff.  There is no way "
      "of going down right now, but looking down you see bones smashed "
      "against the rocks.  Seems this is the elephant's suicide cliff."
    );
    set_items(([
        "bones" : "They are smashed against the rocks.",
        "graveyard" : "It ends here with no way down at the moment.",
        "cliff" : "It is quite steep, the only way down is jumping.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"northeast" : ELE "ele13",
"west" : ELE "ele7",
"northwest" : ELE "ele11",
"north" : ELE "ele12",
    ]) );
}
