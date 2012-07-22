#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "east"      : ROOMS "lost_field002.c",  
        "southwest"      : ROOMS "lost_field019.c",
        "north"     : ROOMS "lost_field026.c",
        
       
      ]));
}
