#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "northeast"      : ROOMS "lost_field016.c",  
        "west"     : ROOMS "lost_field014.c",
        
       
      ]));
}
