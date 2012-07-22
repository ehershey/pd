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
"west" : WATER "lev11",
"south" : WATER "lev4",
"east" : WATER "lev13",
"down" : WATER "ll12",
"up" : WATER "level12",
    ]) );
}
void reset() {
 ::reset();
   if (!present("turtle")) {
      new(MOB"turtle")->move(this_object());
 
    }
}
