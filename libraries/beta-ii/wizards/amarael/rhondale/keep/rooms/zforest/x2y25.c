#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x1y24.c",
  "east" : KEEPROOM"zforest/x2y26.c",
      ]));
}