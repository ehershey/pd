#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "south" : ROOMS "marsh25.c",
		"north" : ROOMS "marsh33.c", ]) );
}  