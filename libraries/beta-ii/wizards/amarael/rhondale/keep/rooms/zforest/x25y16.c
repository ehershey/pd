#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zvillage/gates.c",
  "north" : KEEPROOM"zforest/x24y16.c",
      ]));
}
