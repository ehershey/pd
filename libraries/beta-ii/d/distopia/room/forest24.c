#include <std.h>
#include <hermes.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROOMS"server");
  ::create();
set_exits(([
			"north" : ROOMS"forest21", 
            "south" : ROOMS"forest23", 
  
          ]));
}