#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Town of Umi");
    set_long(
      "On this side of the air-bubble, a coral looking town is up to the north.
"
      "The forcefield is holding back the water, and air is pleanty here. "
      "Outside the air-bubble, fish are swimming in all directions."
          );
    set_items(([
        "town" : "Made of smoothed down coral.",
        "air-bubble" : "Keeps water out and air inside",
        "bubble" : "Keeps water out and air inside",
        "fish" : "All sorts of fish out there, just swimming around",
        "water" : "A deep royal blue in color",
        "path" : "Unusual, it is made of coral, not found in swamps",
        "coral" : "White and pink mostly, and very smooth",
    ]));
    set_listen("default", "Relaxing sounds of water soothing the mind");
    set_exits( ([
"north" : UMI "umi7",
"out" : UMI "umi2",
    ]) );
}
init() {
   ::init();
   
}
