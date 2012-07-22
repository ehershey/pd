#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x23y20.c",
  "northeast" : KEEPROOM"zforest/x23y22.c",
  "east" : KEEPROOM"zforest/x24y22.c",
      ]));
}
