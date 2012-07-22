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
    set_listen("default", "Burbles of air bubbles escaping upwards.");
    set_exits( ([
"west" : WATER "lev9",
"south" : WATER "lev2",
"east" : WATER "lev11",
    ]) );
}
void reset() {
 ::reset();
   if (!present("octopus")) {
      new(MOB"octopus")->move(this_object());
    }
}
