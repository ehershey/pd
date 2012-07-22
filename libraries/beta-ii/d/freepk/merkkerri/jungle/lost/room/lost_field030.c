#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "north"      : ROOMS "lost_field031.c",  
        "east"         : ROOMS "lost_field029.c",
       
      ]));
}
