#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
set_exits((["south":"/wizards/detach/forbiden/rooms/room6",
            "north":"/wizards/detach/forbiden/rooms/room66"]));
}
