#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "north"     : ROOMS "lost_field002.c",
        "south"     : ROOMS "lost_field004.c",        
      ]));
}
