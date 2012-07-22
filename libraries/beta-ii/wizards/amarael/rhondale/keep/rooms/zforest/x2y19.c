#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x1y20.c",
  "southwest" : KEEPROOM"zforest/x3y18.c",
  "east" : KEEPROOM"zforest/x2y20.c",
      ]));
}
