#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "northeast" : ROOMS "marsh49.c",
		"southwest" : ROOMS "marsh35.c", ]) );
}  
