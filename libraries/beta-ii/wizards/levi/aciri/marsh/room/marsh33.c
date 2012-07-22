#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "south" : ROOMS "marsh24.c",
		"southwest" : ROOMS "marsh23.c", ]) );
}  