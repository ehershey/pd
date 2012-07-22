#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southwest" : ROOMS "marsh53.c",
		"east" : ROOMS "marsh57.c" ]) );
}  
