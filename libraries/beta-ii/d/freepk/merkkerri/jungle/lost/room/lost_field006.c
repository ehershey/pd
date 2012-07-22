#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "north"     : ROOMS "lost_field019.c",
        "southwest"      : ROOMS "lost_field007.c",  
        "southeast"      : ROOMS "lost_field005.c",      
      ]));
}
