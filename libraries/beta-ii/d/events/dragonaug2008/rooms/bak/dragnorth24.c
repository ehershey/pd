#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 15, 0 })]));
  set_short("The Great Northern Ridge");
  set_long("The Great Northern Ridge\nThis is the furthest east point alonge the great northern ridge. The ridge runs east and west. The ridge physically connects all of the inner high mountain paths to one another, and symbolically connects each of the four dragon races to one another. "
    +"The ridge dips to the south and the southwest into a large plateau. To the northwest a path disconnects from the great northern ridge and attaches itself to the side of a mountain peak. There is an incredibly deep crevace to the southeast, and a moderately sized crevace to the northeast.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth20.c",
    "west" : DRAG_ROOMS"dragnorth23.c",
    "east" : DRAG_ROOMS"dragnorth25.c",
    "southwest" : DRAG_ROOMS"dragnorth29.c",
    "south" : DRAG_ROOMS"dragnorth30.c",
             ]) );
  set_items( ([
             ]) );
}
