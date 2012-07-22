#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 15, 0 })]));
  set_short("Dragon Lands North");
  set_long("The path scurries along the mountain to the west, heading higher up into the sky to the southeast. The deep crevace to the east is a familiar sight to the mountain area: nondescript, rocky, brown, filled with boulders and very steep. The path slides down the mountain to the northwest. There is a large ridge clearly visible to the southeast, it spans out past the mountain peak to the east and out of view. The path below seems to connect to this ridge ahead to the southeast.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth15.c",
    "southeast" : DRAG_ROOMS"dragnorth24.c",
             ]) );
  set_items( ([
             ]) );
}
