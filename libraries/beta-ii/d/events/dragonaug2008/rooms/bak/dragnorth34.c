#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 16, 0 })]));
  set_short("Dragon Lands North");
  set_long("The southernmost point of the dragon's northern common grounds. The great plateau to the north has been squeezed to a relatively fine point here between two chasms to the east and to the west. A moderately sized ridge is projected from the ground below out towards a second large plateau to the southeast. The crevace to the east looks mysteriously foreboding.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth31.c",
    "north" : DRAG_ROOMS"dragnorth32.c",
    "south" : DRAG_ROOMS"dragnorth36.c",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
