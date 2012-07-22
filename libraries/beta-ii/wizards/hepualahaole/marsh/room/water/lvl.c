#include <std.h>
#include <marsh.h>
inherit OCEAN;
void create() {
ocean::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Swamp waters");
    set_long(
    "%^BLUE%^ In the swampy-waters, swimming.  There's a whirlpool here."
          );
    set_items(([
        "water" : "Mixture of blue and brown.",
        "whirlpool" : "Just water going around clockwise.",
    ]));
    set_listen("default", "Burbles of air bubbles escaping upwards.");
    set_exits( ([
"northwest" : WATER "lvl8",
    ]) );
}
