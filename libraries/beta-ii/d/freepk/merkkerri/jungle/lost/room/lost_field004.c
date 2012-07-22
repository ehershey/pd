#include <std.h>
#include <lost.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
     set_exits(([
        "north"     : ROOMS "lost_field003.c",
        "southwest"     : ROOMS "lost_field005.c",        
      ]));
}
