#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "north" : ROOMS "marsh37.c",
		"south" : ROOMS "marsh22.c",]) );
}  
