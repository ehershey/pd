#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x23y11.c",
  "east" : KEEPROOM"zforest/x24y13.c",
      ]));
}
