#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Town");
    set_day_long(
      "A wall of trees stands firmly along the edge of "
      "town.  A few branches of the wild vines climbs up"
      "wards along the wall to stake it's claim."
          );
    set_night_long(
      "Mounds of wild vines can be seen under the light of "
      "fire-flies.  A dark wall is blocking the escape route "
      "out of the vines."
    );
    set_items(([
        "wall" : "It's made from a bunch of magical trees bounding "
                 "together to form a tight wall.",
        "trees" : "You can't make of it's type, but you feel that "
                  "it's alive in more ways then one.",
        "branch" : "It's climbing steadily upwards.",
        "vine" : "It slowly chocking the life from the town.",
        "flies" : "Unique, it has an actual fire for a body.",
    ]));
    set_listen("default", "Sounds of a busy clamoring town");
    set_exits( ([
"northwest" : TOWN "town10",
    ]) );
}
