#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Town of Umi");
    set_long(
      "As the town comes to an end, the path ends just short of an airbubble, "
      "which seems to be holding back the water.  Outside the bubble, fish "
      "are swimming in all directions."
          );
    set_items(([
        "town" : "Safely hidden from unknown visitors.",
        "air-bubble" : "Keeps water out and air inside",
        "bubble" : "Keeps water out and air inside",
        "fish" : "All sorts of fish out there, just swimming around",
        "water" : "A deep royal blue in color",
        "path" : "Unusual, it is made of coral, not found in swamps",
        "coral" : "White and pink mostly, and very smooth",
    ]));
    set_listen("default", "Relaxing sounds of water soothing the mind");
    set_exits( ([
"northeast" : UMI "umi29",
"north" : UMI "umi28",
"west" : UMI "umi19",
    ]) );
}
