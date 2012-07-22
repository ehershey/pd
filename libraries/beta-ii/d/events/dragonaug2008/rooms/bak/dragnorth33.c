#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 16, 0 })]));
  set_short("Dragon Lands North");
  set_long("The south easternmost point of the dragon's northern common grounds. The great plateau to the northwest has been squeezed to a relatively fine point here between two chasms to the southwest and to the northeast. A large ridgetop path to the southeast connects to the tip of the plateau here, extending the path's reach further into the mountain.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth30.c",
    "west" : DRAG_ROOMS"dragnorth32.c",
    "southeast" : DRAG_ROOMS"dragnorth35.c",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
