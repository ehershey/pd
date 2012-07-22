#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_long("The path skirts the side of the southeastern mountain peak very closely, encroaching up its side and slanting dangerously outwards towards a great drop to the northeast in the process. The path snakes up the side of the mountain peak to the southeast and heads further upward, sliding towards the southeast further up the mountainside, leaving the lower portion of the mountain peak behind.");
  set_exits( ([
    "west" : DRAG_ROOMS"dragnorth12.c",
    "southeast" : DRAG_ROOMS"dragnorth18.c",
             ]) );
  set_items( ([
             ]) );
}
