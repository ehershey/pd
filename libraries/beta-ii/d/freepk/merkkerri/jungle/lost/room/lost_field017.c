#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "east"      : ROOMS "lost_field014.c",  
        "west"      : ROOMS "lost_field008.c",
        "north"     : ROOMS "lost_field005.c",
        
       
      ]));
}
