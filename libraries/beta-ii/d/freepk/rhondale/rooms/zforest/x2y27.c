#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x2y26.c",
  "northeast" : KEEPROOM"zforest/x1y28.c",
  "southwest" : KEEPROOM"zforest/x3y26.c",
      ]));
}
