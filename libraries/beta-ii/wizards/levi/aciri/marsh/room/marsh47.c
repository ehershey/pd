#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "northeast" : ROOMS "marsh53.c",
		"south" : ROOMS "marsh38.c",
		"west" : ROOMS "marsh46.c", ]) );
}  
