#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "northeast" : ROOMS "marsh33.c",
		"west" : ROOMS "marsh22.c",
	 	"north" : ROOMS "marsh32.c", ]) );
}  
