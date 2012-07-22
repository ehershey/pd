#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "east" : KEEPROOM"zforest/x1y18.c",
  "southwest" : KEEPROOM"zforest/x2y16.c",
  "south" : KEEPROOM"zforest/x2y17.c",
      ]));
}
