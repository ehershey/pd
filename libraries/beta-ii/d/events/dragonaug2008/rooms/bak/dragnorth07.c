#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 14, 0 })]));
  set_short("Dragon Lands North");
  set_long("On top of a mountain ridge, the path below runs to the west and slopes gently up along with the mountain to the southeast. The mountain base on both sides of the ridge drop off into large and small brown rocks. The path is firmly beaten into place without a trace of loose brush or foliage to be seen.");
  set_exits( ([
    "west" : DRAG_ROOMS"dragnorth06.c",
    "southeast" : DRAG_ROOMS"dragnorth09.c",
             ]) );
  set_items( ([
             ]) );
}
