#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room143",
           "east" : "/wizards/detach/forbiden/rooms/room160", 
            "west" :"/wizards/detach/forbiden/rooms/room158",
            "north":"/wizards/detach/forbiden/rooms/room179"]));
}
