#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["south":"/wizards/detach/forbiden/rooms/room91",
           "east" : "/wizards/detach/forbiden/rooms/room99", 
            "west" :"/wizards/detach/forbiden/rooms/room89",
            "north":"/wizards/detach/forbiden/rooms/room93"]));
}
