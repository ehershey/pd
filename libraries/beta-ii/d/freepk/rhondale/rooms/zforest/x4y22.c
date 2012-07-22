#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x5y22.c",
  "east" : KEEPROOM"zforest/x4y23.c",
  "northeast" : KEEPROOM"zforest/x3y23.c",
  "northwest" : KEEPROOM"zforest/x3y21.c",
      ]));
}
