#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southwest" : ROOMS "marsh10.c",
                "north" : ROOMS "marsh19.c", ]) );
}  
