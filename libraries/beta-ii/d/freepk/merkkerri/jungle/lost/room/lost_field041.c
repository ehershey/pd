#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "west"      : ROOMS "lost_field040.c",  
        "southwest"      : ROOMS "lost_field042.c",  
       
      ]));
}
