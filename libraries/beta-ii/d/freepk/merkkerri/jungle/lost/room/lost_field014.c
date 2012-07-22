#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "east"      : ROOMS "lost_field015.c",  
        "west"     : ROOMS "lost_field017.c",
        "south"     : ROOMS "lost_field013.c",
        
       
      ]));
}
