#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southeast" : ROOMS "marsh11.c",
                "north" : ROOMS "marsh27.c",
		"northeast" : ROOMS "marsh28.c", ]) );
}  
