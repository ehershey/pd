#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "northwest"      : ROOMS "lost_field007.c",  
        "south"          : ROOMS "lost_field009.c",     
        "east"          : ROOMS "lost_field017.c", 
      ]));
}
