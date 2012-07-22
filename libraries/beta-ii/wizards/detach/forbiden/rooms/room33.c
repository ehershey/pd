#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
set_exits((["south":"/wizards/detach/forbiden/rooms/room32",
           "east" : "/wizards/detach/forbiden/rooms/room26", 
            "west" :"/wizards/detach/forbiden/rooms/room36",
            "north":"/wizards/detach/forbiden/rooms/room34"]));
}

