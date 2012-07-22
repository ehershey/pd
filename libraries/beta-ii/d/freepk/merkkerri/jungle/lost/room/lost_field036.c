#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "east"      : ROOMS "lost_field038.c",  
        "west"      : ROOMS "lost_field034.c",  
        "south"         : ROOMS "lost_field037.c",
       
      ]));
}
