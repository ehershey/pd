#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southwest" : ROOMS "marsh3.c",
                "northeast" : ROOMS "marsh11.c", ]) );
}  
