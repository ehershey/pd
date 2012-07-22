#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southeast" : ROOMS "marsh46.c",
		"southwest" : ROOMS "marsh44.c",
		"south" : ROOMS "marsh45.c",
	 	"northeast" : ROOMS "marsh55.c" ]) );
}  
