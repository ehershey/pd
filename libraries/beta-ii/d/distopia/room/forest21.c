#include <std.h>
#include <hermes.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROOMS"server");
  ::create();
set_exits(([
           "south" : ROOMS"forest24", 
			
            "southwest" : ROOMS"forest9", 
            "north" : ROOMS"forest5",
          ]));
}
