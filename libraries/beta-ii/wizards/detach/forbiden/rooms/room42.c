#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
set_exits((["west":"/wizards/detach/forbiden/rooms/room51",
              "north" :"/wizards/detach/forbiden/rooms/room43",
              "south":"/wizards/detach/forbiden/rooms/room41"]));
}
