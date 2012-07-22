#include <std.h>
#include <marsh.h>
inherit DESERT;
void create() {
desert::create();
   set_properties( ([ "light" : 2]) );
    set_property("desert",1);
    set_short("Sabai Desert");
    set_day_long(
      "A large boulder stands out."
    );
    set_night_long(
      "A large boulder stands out."
    );
    set_items(([
        "desert" : "Lots and lots of sand.",
        "cactus" : "A big thorny plant.",
        "cactuses" : "A bunch of big thorny plants scatter across the desert.",
        "trees" : "Palm trees out in the distance.",
        "water" : "It's off in the distance, surrounded by palm trees.",
        "boulder" : "Nothing special about it, might want to come back in "
                    "three months or so.",
        "stars" : "Fills the night-sky.",
      ]));
    set_smell("default", "It smells of dry sand");
    set_listen("default", "Sounds very quiet, and still");
    set_exits( ([
"out" : SAB "sab24",
    ]) );
}
