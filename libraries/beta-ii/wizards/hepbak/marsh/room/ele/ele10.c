#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
      "There are bones to the west shoved there, making it difficult to travel
"
      "in that direction. Across the graveyard to the southeast, there are "
      "elephant's ending their life by jumping the cliff.  To the east of the "
      " land, more elephants dying of a harsh disease."
    );
    set_night_long(
      "There are bones to the west shoved there, making it difficult to travel
"
      "in that direction. Across the graveyard to the southeast, there are "
      "elephant's ending their lives by jumping the cliff.  To the east of the
"
      " land, more elephants dying of a harsh disease."
    );
    set_items(([
        "bones" : "They are shoved to the west, It seems to be a way of
clearing
 the marsh",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"northeast" : ELE "ele17",
"east" : ELE "ele11",
"southeast" : ELE "ele7",
"north" : ELE "ele16",
    ]) );
}
void reset() {
 ::reset();
   if (!present("melephant")) {
      new(MOB"melephant")->move(this_object());
   }
}
