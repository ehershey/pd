#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "southwest"      : ROOMS "lost_field015.c",  
        
       
      ]));
}
