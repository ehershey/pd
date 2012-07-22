#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "west"      : ROOMS "lost_field029.c",  
        "south"         : ROOMS "lost_field027.c",
        "northeast"     : ROOMS "lost_field044.c",
       
      ]));
}
