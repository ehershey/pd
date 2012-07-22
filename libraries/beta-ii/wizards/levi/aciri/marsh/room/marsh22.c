#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "east" : ROOMS "marsh23.c",
		"west" : ROOMS "marsh21.c",
	 	"north" : ROOMS "marsh31.c" ]) );
}  
