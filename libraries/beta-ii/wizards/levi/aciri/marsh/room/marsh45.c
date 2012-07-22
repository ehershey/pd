#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "east" : ROOMS "marsh46.c",
		"west" : ROOMS "marsh44.c",
		"north" : ROOMS "marsh52.c", ]) );
}  
