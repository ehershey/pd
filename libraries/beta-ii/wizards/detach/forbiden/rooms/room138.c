#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
 
 
set_exits((["north":"/wizards/detach/forbiden/rooms/room149",
              "east" :"/wizards/detach/forbiden/rooms/room139",
              "west":"/wizards/detach/forbiden/rooms/room137"]));
}
