#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room131",
           "east" : "/wizards/detach/forbiden/rooms/room142", 
            "west" :"/wizards/detach/forbiden/rooms/room140",
            "north":"/wizards/detach/forbiden/rooms/room157"]));
}
