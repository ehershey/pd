#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x8y5.c",
  "southeast" : KEEPROOM"zforest/x10y6.c",
  "south" : KEEPROOM"zforest/x10y5.c",
      ]));
}
