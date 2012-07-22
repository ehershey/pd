#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : -1, "no teleport" : 1, "mountain" : 1, "indoors" : 1, "coords" : ({ 137, 17, 0 })]));
  set_short("%^BLACK%^%^BOLD%^Realm of the Black Dragon%^RESET%^");
  set_long("%^BLACK%^%^BOLD%^Realm of the Black Dragon%^RESET%^\n"
    +"Deep in a dark crevace, no natural light pervades this place. The area is illuminated by a soft, dark light, which seems to emanate from a strange large rock embedded in the middle of the ground. Jagged overhangs above stretch over and block out the sky. There is a dark path that leads up the side of the mountain to the east back onto the mountain top. The moist, dark rock walls of the mountain peaks and ridges close in from all directions, breeding a foreboding and uninviting, yet strangely nurturing feeling.");
  set_exits( ([
    "east" : DRAG_ROOMS"dragnorth38.c",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  while(!present("dragon 4"))
    new(DRAG_MOBS"blackdragon.c")->move(this_object());
}
