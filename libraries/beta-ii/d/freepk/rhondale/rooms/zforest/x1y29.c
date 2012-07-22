#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x2y29.c",
  "west" : KEEPROOM"zforest/x1y28.c",
  "east" : KEEPROOM"zforest/x1y30.c",
      ]));
}
