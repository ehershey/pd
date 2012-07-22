#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "west" : ROOMS "marsh56.c",
                "east" : ROOMS "marsh58.c",
		"north" : ROOMS "tob1.c", ]) );
  add_invis_exit("north");
}  
