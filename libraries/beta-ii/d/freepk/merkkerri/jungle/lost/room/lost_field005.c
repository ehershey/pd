#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "northeast"     : ROOMS "lost_field004.c",
        "northwest"     : ROOMS "lost_field006.c",  
        "south"         : ROOMS "lost_field017.c",      
      ]));
}
