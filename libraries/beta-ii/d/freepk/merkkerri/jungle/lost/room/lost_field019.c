#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "northeast"      : ROOMS "lost_field018.c",  
        "south"      : ROOMS "lost_field006.c",
        "west"     : ROOMS "lost_field020.c",
        
       
      ]));
}
