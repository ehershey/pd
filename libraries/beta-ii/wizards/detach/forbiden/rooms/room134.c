#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
 
set_exits((["north":"/wizards/detach/forbiden/rooms/room144",
              "east" :"/wizards/detach/forbiden/rooms/room127",
              "west":"/wizards/detach/forbiden/rooms/room133"]));
}
