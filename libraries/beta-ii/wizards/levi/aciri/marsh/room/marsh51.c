#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southeast" : ROOMS "marsh44.c",
		"southwest" : ROOMS "marsh43.c", ]) );
}  
