#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 16, 0 })]));
  set_short("Dragon Lands North");
  set_long("A large plateau that extends in every direction but to west. The plateau is well-travelled and has been trampled into place from diligent use. It serves as a common area for the dragons, color-indiscriminate. To the west, the plateau gives way to a large mountain peak which springs up seemingly out of nowhere. The peak ends abruptly to the northwest, but continues for a good distance towards the southwest.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth23.c",
    "northeast" : DRAG_ROOMS"dragnorth24.c",
    "east" : DRAG_ROOMS"dragnorth30.c",
    "south" : DRAG_ROOMS"dragnorth31.c",
    "southeast" : DRAG_ROOMS"dragnorth32.c",
             ]) );
  set_items( ([
             ]) );
}
void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
