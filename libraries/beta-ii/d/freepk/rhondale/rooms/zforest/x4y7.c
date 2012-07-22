#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x3y6.c",
  "east" : KEEPROOM"zforest/x4y8.c",
  "southwest" : KEEPROOM"zforest/x5y6.c",
      ]));
}
