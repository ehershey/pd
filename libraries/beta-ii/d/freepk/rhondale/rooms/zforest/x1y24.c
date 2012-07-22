#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x2y25.c",
  "west" : KEEPROOM"zforest/x1y23.c",
      ]));
}
