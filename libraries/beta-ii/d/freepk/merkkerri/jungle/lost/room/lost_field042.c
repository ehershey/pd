#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "west"      : ROOMS "lost_field038.c",  
        "northeast"      : ROOMS "lost_field041.c", 
        "south"      : ROOMS "lost_field043.c",   
       
      ]));
}
