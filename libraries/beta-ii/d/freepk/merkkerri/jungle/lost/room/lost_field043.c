#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "north"      : ROOMS "lost_field042.c",  
        "southwest"      : ROOMS "lost_field044.c", 
       
      ]));
}
