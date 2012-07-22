#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Town");
    set_day_long(
      "The town is hidden underneath a wild growth of vines.  Bits "
      "and pieces of buildings peek through the over-growth.  Workers "
      "scramble with no preveil, of ridding the town of the infestation "
      "of vines."
          );
    set_night_long(
      "Mounds of wild vines can be seen under the light of fire-flies."
    );
    set_items(([
        "town" : "Can't see much of it, the wild vines limits"
                 "how far you can see.",
        "vines" : "It chokes the land, and everything it touches.",
        "buildings" : "Can't see much of the buildings from here.",
        "workers" : "They look and sound very tired.",
        "flies" : "Unique, they actually have a flame for a body.",
    ]));
    set_listen("default", "Sounds of a busy clamoring town");
    set_exits( ([
"west" : TOWN "town9",
"northwest" : TOWN "town14",
"southeast" : TOWN "town7",
    ]) );
}
void reset() {
 ::reset();
   if (!present("lizardmachete")) {
      new(MOB"lizardmachete")->move(this_object());
  if (!present("lizardsickle"))
     new(MOB"lizardsickle")->move(this_object());
 
    }
}
