#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "east"      : ROOMS "lost_field001.c",
        "west"      : ROOMS "lost_field018.c",
        "south"     : ROOMS "lost_field003.c",        
      ]));
}
