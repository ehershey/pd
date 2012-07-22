#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Field");
    set_day_long(
      "Long grass replaces the gnarly vines.  A distint path divides "
      "the blades in an east to west direction.  A hut appears at "
      "either end."
          );
    set_night_long(
      "Long grass sways to the rythem of the gentle breeze."
    );
    set_items(([
        "grass" : "Not a native plant for this region.",
        "vines" : "It is choking the life out of the land.",
        "path" : "The grass parts enough, to lead you east or west.",
        "hut" : "They look inviting enough.",
    ]));
    set_listen("default", "Sounds of grass hushing in the breeze.");
    set_exits( ([
"east" : TOWN "town3",
"west" : TOWN "town",
"north" : TOWN "town4",
    ]) );
}
