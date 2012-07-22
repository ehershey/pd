#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_long("The large plateau below is of good size and impressive construction. This is the south eastern portion of the dragon's western common area. The ground below is well-travelled and flattened firm, such that it would serve as a wonderful meeting place for any that would wish to use it as such. To the south and the south-east, the plateau connects to an impressively large ridge that leads to the east and to the west. The ridge to the southeast cuts off the impressive canyon that extends to the east and far to the north.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth40.c",
    "north" : DRAG_ROOMS"dragnorth41.c",
    "west" : DRAG_ROOMS"dragnorth43.c",
    "southeast" : DRAG_ROOMS"tradepath2",
    "south" : DRAG_ROOMS"tradepath1",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
