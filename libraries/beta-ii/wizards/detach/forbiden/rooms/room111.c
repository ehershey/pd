#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
set_exits((["north":"/wizards/detach/forbiden/rooms/room112",
            "east":"/wizards/detach/forbiden/rooms/room116"]));
}
