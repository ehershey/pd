#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room146",
           "east" : "/wizards/detach/forbiden/rooms/room157", 
            "west" :"/wizards/detach/forbiden/rooms/room155",
            "north":"/wizards/detach/forbiden/rooms/room176"]));
}