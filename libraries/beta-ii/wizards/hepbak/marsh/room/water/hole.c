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
"down" : WATER "level12",
"surface" : ROOMS "surface",
    ]) );
}
void init()
{
 ::init();
 add_action("Fsurface", "surface");
}
int Fsurface()
{
 write("%^BOLD%^%^WHITE%^You take in a big breath of cool air.");
 return 0;
}
void reset() {
 ::reset();
   if (!present("shark")) {
      new(MOB"shark")->move(this_object());
      new(MOB"shark")->move(this_object());
      new(MOB"shark")->move(this_object());
 
    }
}
