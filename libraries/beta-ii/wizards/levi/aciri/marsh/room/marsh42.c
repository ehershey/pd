#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( (["north" : ROOMS "marsh50.c",
	       "east" : ROOMS "marsh43.c", ]) );
}  
