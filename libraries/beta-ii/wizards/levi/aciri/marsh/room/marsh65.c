#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "west" : ROOMS "marsh63.c",
		"north" : ROOMS "marsh68.c" ]) );
}  
