#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room99",
           "east" : "/wizards/detach/forbiden/rooms/room101", 
            "west" :"/wizards/detach/forbiden/rooms/room93",
            "north":"/wizards/detach/forbiden/rooms/room97"]));
}
