#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x11y22.c",
  "west" : KEEPROOM"zforest/x10y21.c",
  "east" : KEEPROOM"zforest/x10y23.c",
      ]));
}
