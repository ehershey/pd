#include <std.h>
inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["east":"/wizards/detach/forbiden/rooms/room131",
           "north" : "/wizards/detach/forbiden/rooms/room140"]));
}
