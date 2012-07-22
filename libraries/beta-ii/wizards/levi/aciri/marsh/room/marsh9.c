#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southeast" : ROOMS "marsh4.c",
                "north" : ROOMS "marsh14.c", ]) );
}  
