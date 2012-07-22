#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "west" : ROOMS "marsh67.c",
		"north" : ROOMS "marsh69.c",
		"south" : ROOMS "marsh65.c" ]) );
}  
