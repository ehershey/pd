#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
set_exits((["south":"/wizards/detach/forbiden/rooms/room115",
            "west":"/wizards/detach/forbiden/rooms/room113"]));
}
