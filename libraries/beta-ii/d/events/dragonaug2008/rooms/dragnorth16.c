#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_long("The mountain path below slides deeply up the side of the mountain, sloping dangerously towards the canyon crevace to the west. The path slips upward slightly to the south where it levels out and then suddenly swerves and smashes into the side of the mountain, leaving a great hole behind as it burrows deeply into the heart of the mountain, towards the east. Towards the northwest, the path eases itself off the side of the mountain peak and rights itself on top of a mountain ridge, where it rounds the bend to the north and disappears from view behind the mountain peak.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth11.c",
    "east" : DRAG_ROOMS"dragnorth17.c",
             ]) );
  set_items( ([
             ]) );
}
