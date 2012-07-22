#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
set_exits((["north":"/wizards/detach/forbiden/rooms/room51",
              "south" :"/wizards/detach/forbiden/rooms/room53",
              "east":"/wizards/detach/forbiden/rooms/room41"]));
}
void reset() {
    ::reset();
     if (children("/wizards/detach/forbiden/mon/wolfmaster2.c")==({})||
         sizeof(children("/wizards/detach/forbiden/mon/wolfmaster2.c"))<3)
            new("/wizards/detach/forbiden/mon/wolfmaster2.c")->move(this_object());
        
}
