#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room136",
           "east" : "/wizards/detach/forbiden/rooms/room148", 
            "west" :"/wizards/detach/forbiden/rooms/room146",
            "north":"/wizards/detach/forbiden/rooms/room163"]));
}
