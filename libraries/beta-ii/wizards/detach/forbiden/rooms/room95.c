#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room94",
           "east" : "/wizards/detach/forbiden/rooms/room96", 
            "west" :"/wizards/detach/forbiden/rooms/room86",
            "north":"/wizards/detach/forbiden/rooms/room117"]));
}
