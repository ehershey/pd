#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "west" : ROOMS "marsh26.c",
		"south" : ROOMS "marsh16.c", ]) );
}  
