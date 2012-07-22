#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "west" : ROOMS "marsh6.c",
                "south" : ROOMS "marsh3.c", ]) );
}  
