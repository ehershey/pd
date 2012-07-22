#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "south" : ROOMS "marsh9.c",
                "west" : ROOMS "marsh13.c",
		"north" : ROOMS "marsh17.c", ]) );
}  
