#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 16, 0 })]));
  set_short("Dragon Lands North");
  set_long("A large plateau that extends in every direction but to the east, where it drops off into a tremendous chasm. The plateau is well-travelled and has been trampled into place from diligent use. It serves as a common area for the dragons, color-indiscriminate.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth23.c",
    "north" : DRAG_ROOMS"dragnorth24.c",
    "west" : DRAG_ROOMS"dragnorth29.c",
    "southwest" : DRAG_ROOMS"dragnorth31.c",
    "south" : DRAG_ROOMS"dragnorth32.c",
    "southeast" : DRAG_ROOMS"dragnorth33.c",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
