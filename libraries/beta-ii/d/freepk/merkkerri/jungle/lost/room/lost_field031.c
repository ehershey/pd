#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "north"      : ROOMS "lost_field032.c",  
        "northeast"         : ROOMS "lost_field035.c",
        "south"         : ROOMS "lost_field030.c",
       
      ]));
}
