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
"southeast" : WATER "lev",
"north" : WATER "lev18",
"east" : WATER "lev9",
    ]) );
}
void reset() {
 ::reset();
   if (!present("humu")) {
      new(MOB"humu")->move(this_object());
 
    }
}