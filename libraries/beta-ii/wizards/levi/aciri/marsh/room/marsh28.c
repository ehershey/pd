#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "northwest" : ROOMS "marsh34.c",
                "southwest" : ROOMS "marsh16.c", ]) );
}
