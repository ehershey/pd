#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x14y29.c",
  "southwest" : KEEPROOM"zforest/x16y28.c",
      ]));
}
