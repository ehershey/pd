#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room92",
           "east" : "/wizards/detach/forbiden/rooms/room98", 
            "west" :"/wizards/detach/forbiden/rooms/room88",
            "north":"/wizards/detach/forbiden/rooms/room94"]));
}