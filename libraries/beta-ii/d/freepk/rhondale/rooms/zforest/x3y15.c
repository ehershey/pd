#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x4y16.c",
  "south" : KEEPROOM"zforest/x4y15.c",
  "northeast" : KEEPROOM"zforest/x2y16.c",
  "northwest" : KEEPROOM"zforest/x2y14.c",
      ]));
}
