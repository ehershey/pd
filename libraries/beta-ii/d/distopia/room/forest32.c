#include <std.h>
#include <hermes.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROOMS"server");
  ::create();
set_exits(([
           "northwest" : ROOMS"forest31", 
			"northeast" : ROOMS"forest33", 
        
          ]));
}
