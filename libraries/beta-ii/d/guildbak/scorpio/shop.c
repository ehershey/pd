// Coded by Whit
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Black Force Shop");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );

    set_long("This is the Black Force Shop keep.  The walls are lined with goods that have been collected throughout the world.  A small lady stands behind a counter towards the north side of the room.");
set_exits(([ "south" : ROOMS"blackforce/hall",
              ]) );
set_items(([
"sign" : "If you need any help please type <help shops>",
]));
}
void reset() {
::reset();
if (!present("lisa"))
          new("/wizards/whit/bfgui/bf_lisa.c")->move(this_object());
  }
