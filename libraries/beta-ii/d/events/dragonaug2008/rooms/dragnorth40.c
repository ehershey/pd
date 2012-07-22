#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_long("The mountain ridge expands and lays out before another plateau of good size, but one that is smaller than that which lies to the northwest. The ground below is well-travelled and flattened firm, such that it would serve as a wonderful meeting place for any that would wish to use it as such.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth36.c",
    "east" : DRAG_ROOMS"dragnorth41.c",
    "south" : DRAG_ROOMS"dragnorth43.c",
    "southeast" : DRAG_ROOMS"dragnorth44.c",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
