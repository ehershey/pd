#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "east"      : ROOMS "lost_field036.c",  
        "south"         : ROOMS "lost_field035.c",
        "west"      : ROOMS "lost_field033.c",
       
      ]));
}
