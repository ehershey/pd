#include <std.h>
#include <marsh.h>
inherit OCEAN;
void create() {
ocean::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Swamp waters");
    set_long(
      "%^BLUE%^ In the swampy-waters, swimming."
          );
    set_items(([
        "water" : "Mixture of blue and brown.",
    ]));
"west" : WATER "lev21",
}
#include <std.h>
#include <marsh.h>
inherit OCEAN;
    ]));
    set_listen("default", "Burbles of air bubbles escaping upwards.");
    set_exits( ([
"north" : WATER "lev23",
"west" : WATER "lev19",
"east" : WATER "lev21",
    ]) );
}
