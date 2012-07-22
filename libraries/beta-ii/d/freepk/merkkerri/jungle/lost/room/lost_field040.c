#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "west"      : ROOMS "lost_field039.c",  
        "east"      : ROOMS "lost_field041.c",  
       
      ]));
}
