// Coding by Whit
// Coded for Primal Darkness
// treetop_3.c

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
    set_short("Amoung the Tree Tops");
    set_day_long("The boards continue to creak as they are walked over.  There "
		 "are small faeries that inhabit the abandoned walkways.  The "
		 "light shines throughout this area making it very bright.  The "
		 "occasional crack makes it easy to look through to see the "
		 "path under the walkway.");
    set_night_long("The boards continue to creak as they are walked over.  There "
		 "are small faeries that inhabit the abandoned walkways.  The "
		 "stars shine through the tree tops making a spectacular view "
		 "of the darkened sky.");
    set_items(([
        "crack" : "Leaves have covered the hole and you are unable to see through it",
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "east" : ROOMS+"treetop4.c",
        "west" : ROOMS+"treetop2.c",
	"northeast" : ROOMS+"treetop5.c"
    ]));
}
void reset() {
    ::reset();
    if (!present("faerie"))
          new(MON+"faerie2.c")->move(this_object());
    if (!present("blue faerie"))
	  new(MON+"faerie1.c")->move(this_object());
  }
