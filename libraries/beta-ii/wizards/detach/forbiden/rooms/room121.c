#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room104",
           "east" : "/wizards/detach/forbiden/rooms/room124", 
            "west" :"/wizards/detach/forbiden/rooms/room120",
            "north":"/wizards/detach/forbiden/rooms/room122"]));
}
