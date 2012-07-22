#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("building",1);
    set_short("outside a tower");
    set_long(
      "Inside the fountain, a heavenly figure rests. She lives in this "
      "lonely area alone and for some unknown reason. A tiny cot lies "
      "in the corner. "
    );
    set_items(([
	"cot" : "An old, beat up cot. It doesn't look too comfortable. ",
    ]));
   set_listen("default", "The steady drip... drip... drip of water.");
   set_exits( ([ 
        "out" : ROOMS"room22.c",
    ]) );
}
void reset() {
::reset();
     if(!present("angeline.c"))
new(MOB"angeline")->move(this_object());
}
