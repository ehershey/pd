#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
set_exits((["west":"/wizards/detach/forbiden/rooms/room45",
              "south" :"/wizards/detach/forbiden/rooms/room36",
              "east":"/wizards/detach/forbiden/rooms/room34"]));
}
