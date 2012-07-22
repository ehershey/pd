#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_long("A large plateau that extends in every direction but to the southeast, where it drops off into a large crevace. The plateau is well-travelled and has been trampled into place from diligent use. It serves as a common area for the dragons, color-indiscriminate. The plateau forks off into two points, one to the south and one to the east.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth29.c",
    "north" : DRAG_ROOMS"dragnorth30.c",
    "west" : DRAG_ROOMS"dragnorth31.c",
    "east" : DRAG_ROOMS"dragnorth33.c",
    "south" : DRAG_ROOMS"dragnorth34.c",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
