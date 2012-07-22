#include <std.h>

inherit ROOM;

void create() {
  ::create();

  set("short", "Room");
  set("long", "Sample 10\n");

  set_exits(([
    "south" : "/wizards/pyro/personal/workroom_main",
    "dragon" : "/d/events/dragonaug2008/rooms/dragnorth01.c",
    "cave" : "/d/events/dragonaug2008/rooms/py/entrance.c",
    "drag_d" : "/d/events/dragonaug2008/drag_d",
   ]));
}
