#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "northeast"      : ROOMS "lost_field010.c",  
        
       
      ]));
}
