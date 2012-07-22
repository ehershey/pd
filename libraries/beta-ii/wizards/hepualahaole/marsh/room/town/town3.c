#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Field.");
    set_day_long(
      "Looking towards the center of the town, vines are "
      "on a zealous rampage to control the land, while the "
      "citizens are fighting back.  Around the hut there is "
      "grass, and curiously enough, not one branch of the "
      "vine dares to cross it's threshold."
          );
    set_night_long(
      "Long grass sways to the rythem of the gentle breeze "
    );
    set_items(([
        "grass" : "The grass is not from here.",
        "vines" : "It seems to be afraid of the grass.",
        "citizens" : "Are looking quite tired of fighting "
                     "the vines all the time.",
        
    ]));
    set_listen("default", "Sounds of grass hushing in the breeze");
    set_exits( ([
"west" : TOWN "town2",
"enter" : TOWN "hut2",
    ]) );
}
void reset() {
 ::reset();
   if (!present("hut", this_object()))
     new( ITEMS "ahut.c" )->move(this_object());
}
