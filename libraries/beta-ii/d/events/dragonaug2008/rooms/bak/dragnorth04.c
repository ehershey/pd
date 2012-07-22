#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 14, 0 }), "coords" : ({ 137, 14, 0 })]));
    set_short("Dragon Lands North");
    set_long("The mountain-side path slips across the side of the mountain peak, where it clambers atop the height of the mountain to the southeast. The foliage and mountain brush that scatters the land to the northwest is rapidly thinned out here. It does not appear that the foliage has thinned out of its own accord however; it almost looks as if it has been trampled to death. Similarly, the ground and the path below appears to be moderately well tended, although unused.");
    set_exits( ([
	"northwest" : DRAG_ROOMS"dragnorth03.c",
	"southeast" : DRAG_ROOMS"dragnorth05.c",
      ]) );
    set_items( ([
    "path": "It heads up into the mountain.",
      ]) );
}
