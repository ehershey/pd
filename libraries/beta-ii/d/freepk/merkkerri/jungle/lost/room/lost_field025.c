#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "east"      : ROOMS "lost_field026.c",  
        "west"         : ROOMS "lost_field024.c",
       
      ]));
}
