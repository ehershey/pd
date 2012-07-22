#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("The Great Northern Ridge");
  set_long("The Great Northern Ridge\nThis is the furthest east point alonge the great northern ridge. The ridge runs east and west. The ridge physically connects all of the inner high mountain paths to one another, and symbolically connects each of the four dragon races to one another. "
    +"The path dips slightly to the north, where it then rises and joins the greater plateau to the north. A mountain peak rises up beyond the ridge to the south, atop which the tops of a few trees can be seen swaying in the wind.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth22.c",
    "west" : DRAG_ROOMS"dragnorth26.c",
    "east" : DRAG_ROOMS"dragnorth28.c",
             ]) );
  set_items( ([
             ]) );
}
