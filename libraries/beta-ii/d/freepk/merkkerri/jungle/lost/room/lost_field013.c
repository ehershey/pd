#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "south"      : ROOMS "lost_field012.c",  
        "north"     : ROOMS "lost_field014.c",
        
       
      ]));
}
