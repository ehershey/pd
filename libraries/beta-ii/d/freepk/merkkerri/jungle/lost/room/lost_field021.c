#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "east"      : ROOMS "lost_field020.c",  
        "west"     : ROOMS "lost_field022.c",
        "north"     : ROOMS "lost_field023.c",
        
       
      ]));
}
