#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Field");
    set_day_long(
      "Looking towards the center of the town, vines are on a zealous "
      "rampage to control the land, while citizens are fighting back.  "
      "Around the hut there is grass, and curiously enough, not one "
      "branch of the vine dares to cross it's threshold."
          );
    set_night_long(
      "Long grass sways to the rythem of the gentle breeze. "
    );
    set_items(([
        "grass" : "The grass is not from these parts.",
        "vines" : "It chokes the land, slowly.",
        "citizens" : "Working very hard to rid the town of vines.",
    ]));
    set_listen("default", "Sounds of grass hushing in the breeze.");
    set_exits( ([
"east" : TOWN "town2",
"enter" : TOWN "hut",
    ]) );
}
void reset() {
 ::reset();
   if (!present("hut", this_object()))
     new( ITEMS "ahut.c" )->move(this_object());
}
