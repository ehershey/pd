#include <std.h>
#include <hermes.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROOMS"server");
  ::create();
set_exits(([
           "southeast" : ROOMS"forest33", 
			"west" : ROOMS"forest26", 
            "northeast" : ROOMS"forest25", 
            
          ]));
}
