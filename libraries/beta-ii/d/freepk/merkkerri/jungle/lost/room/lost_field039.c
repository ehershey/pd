#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "south"      : ROOMS "lost_field038.c",  
        "east"      : ROOMS "lost_field040.c",  
       
      ]));
}
