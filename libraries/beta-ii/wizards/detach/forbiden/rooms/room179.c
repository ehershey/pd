#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
 
 
set_exits((["south":"/wizards/detach/forbiden/rooms/room159",
              "east" :"/wizards/detach/forbiden/rooms/room180",
              "west":"/wizards/detach/forbiden/rooms/room178"]));
}
