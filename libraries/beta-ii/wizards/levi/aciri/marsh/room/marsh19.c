#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "east" : ROOMS "marsh20.c",
                "south" : ROOMS "marsh15.c",
                "north" : ROOMS "marsh30.c",
                "west" : ROOMS "marsh18.c", ]) );
}  
