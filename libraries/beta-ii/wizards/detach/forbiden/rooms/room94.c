#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room93",
           "east" : "/wizards/detach/forbiden/rooms/room97", 
            "west" :"/wizards/detach/forbiden/rooms/room87",
            "north":"/wizards/detach/forbiden/rooms/room95"]));
}
