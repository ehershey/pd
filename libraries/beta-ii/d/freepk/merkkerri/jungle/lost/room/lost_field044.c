#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "northeast"      : ROOMS "lost_field043.c",  
        "southwest"      : ROOMS "lost_field028.c", 
       
      ]));
}
