#include <std.h>
#include <dragonevent.h>

inherit DRAG_MOBS"flyingdragon.c";

void create() {
  ::create();
  set_aggressive( 20 );
  set_moving(1);
  set_speed(6);
  set_boundaries(131, 146, 10, 27, 0, 1);
}

void gotosleep() { return; }
