#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "north"      : ROOMS "lost_field008.c",  
        "southeast"          : ROOMS "lost_field010.c",     
       
      ]));
}
