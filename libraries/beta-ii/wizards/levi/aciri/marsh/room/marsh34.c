#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southeast" : ROOMS "marsh28.c",
		"north" : ROOMS "marsh40.c", ]) );
}  
