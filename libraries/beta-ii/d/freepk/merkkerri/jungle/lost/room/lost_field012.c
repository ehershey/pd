#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "west"      : ROOMS "lost_field010.c",  
        "north"     : ROOMS "lost_field013.c",
        
       
      ]));
}
