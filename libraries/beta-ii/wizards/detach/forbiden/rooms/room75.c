#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room76",
           "east" : "/wizards/detach/forbiden/rooms/room79", 
            "west" :"/wizards/detach/forbiden/rooms/room70",
            "north":"/wizards/detach/forbiden/rooms/room74"]));
}
