#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
 
set_exits((["east":"/wizards/detach/forbiden/rooms/room123",
              "south" :"/wizards/detach/forbiden/rooms/room121",
              "west":"/wizards/detach/forbiden/rooms/room119"]));
}
