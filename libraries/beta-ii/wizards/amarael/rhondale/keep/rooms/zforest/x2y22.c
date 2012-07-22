#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x1y23.c",
  "east" : KEEPROOM"zforest/x2y23.c",
  "west" : KEEPROOM"zforest/x2y21.c",
      ]));
}
