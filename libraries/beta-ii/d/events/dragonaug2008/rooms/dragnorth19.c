#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_long("The only things that can be seen from here are the mountain to the south, the path below, and the ocean off to the west. The path spreads out and rises up the mountain path to the northeast, where it flattens out atop a large ridge, obstructing the view to the south. To the northwest, the path rounds a bend in the mountain and curves out of sight, leaving only the sight of the ocean far beyond it. The tall mountain peak obscures any view there might be to the east, and the path curves up to a lip on the west, obscuring any view of the ground below.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth14.c",
    "southeast" : DRAG_ROOMS"dragnorth23.c",
             ]) );
  set_items( ([
             ]) );
}
