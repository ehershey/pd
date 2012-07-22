#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "east" : ROOMS "marsh13.c",
                "west" : ROOMS "marsh11.c", ]) );
}  
