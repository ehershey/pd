#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
 
set_exits((["south":"/wizards/detach/forbiden/rooms/room188",
                "east" : "/d/helgrath/tundra/too/room7",
                /*"west" : "/d/helgrath/tundra/too/room6",*/]));
add_pre_exit_function("east", "go_south");
add_pre_exit_function("west", "go_south"); 
}
void reset() {
    ::reset();
     if (children("/wizards/detach/forbiden/mon/wolfmaster2.c")==({})||
         sizeof(children("/wizards/detach/forbiden/mon/wolfmaster2.c"))<2)
            new("/wizards/detach/forbiden/mon/wolfmaster2.c")->move(this_object());
        
}
int go_south() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
