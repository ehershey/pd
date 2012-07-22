#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_long("The large plateau below is of good size and impressive construction. This is the south western most portion of the dragon's western common area. he ground below is well-travelled and flattened firm, such that it would serve as a wonderful meeting place for any that would wish to use it as such. To the south east, the plateau connects to an impressively large ridge that runs off towards the east. To the west, the mountain side drops off steeply towards the ground, which is of an impressive distance away from the plateau.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth40.c",
    "northeast" : DRAG_ROOMS"dragnorth41.c",
    "east" : DRAG_ROOMS"dragnorth44.c",
    "southeast" : DRAG_ROOMS"tradepath1",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
