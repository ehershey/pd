#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x1y19.c",
  "southwest" : KEEPROOM"zforest/x2y19.c",
  "southeast" : KEEPROOM"zforest/x2y21.c",
      ]));
}
