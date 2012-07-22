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
"south" : WATER "level15",
"east" : WATER "level22",
"west" : WATER "level20",
    ]) );
}
void reset() {
 ::reset();
   if (!present("shark")) {
      new(MOB"shark")->move(this_object());
 
    }
}
