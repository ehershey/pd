#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "northwest"      : ROOMS "lost_field009.c",  
        "southwest"          : ROOMS "lost_field011.c",  
        "east"          : ROOMS "lost_field012.c",   
       
      ]));
}