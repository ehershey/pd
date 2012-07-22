#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 138, 17, 0 })]));
  set_short("Dragon Lands North");
  set_long("The large plateau below is of good size and impressive construction. This is the northeastern portion of the dragon's western common area. The ground below is well-travelled and flattened firm, such that it would serve as a wonderful meeting place for any that would wish to use it as such. To the north, the plateau narrows and extends between two deep canyons, one to the northwest and the other to the east. The canyon to the east is so large that the other side of it, should there be one, cannot be seen from here.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth38.c",
    "west" : DRAG_ROOMS"dragnorth40.c",
    "southwest" : DRAG_ROOMS"dragnorth43.c",
    "south" : DRAG_ROOMS"dragnorth44.c",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
