#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "east"      : ROOMS "lost_field019.c",  
        "west"     : ROOMS "lost_field021.c",
        
       
      ]));
}
