#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "northwest" : ROOMS "marsh35.c",
		"south" : ROOMS "marsh17.c" ]) );
}  
