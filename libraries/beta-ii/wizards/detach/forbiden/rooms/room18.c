#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
set_exits((["south":"/wizards/detach/forbiden/rooms/room15",
            "north":"/wizards/detach/forbiden/rooms/room19"]));
}
