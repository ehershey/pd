#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Marsh");
    set_day_long(
      "Walking on a not so sturdy plank, which is over a very swampy marsh. "
    );
    set_night_long(
      "Guided only by moonlight, the plank looks worst now then it did in "
      "the daytime.  There are creepy eyes all around."
    );
    set_items(([
        "marsh" : "There are bones sticking out of the mud and dead trees.",
        "mud" : "Mixture of dirt and water, mostly water.",
        "eyes" : "Red eyes glowing everywhere.",
        "plank" : "Not very much effort was made in making of this wooden "
                  "plank.",
    ]));
    set_smell("default", "It smells of muddy waters.");
    set_listen("default", "Sounds of creatures splashing in a distance");
    set_exits( ([
"north" : ROOMS "docks3",
"south" : ROOMS "docks",
    ]) );
}
