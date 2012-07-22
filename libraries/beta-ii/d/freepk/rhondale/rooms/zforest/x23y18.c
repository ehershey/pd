#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "east" : KEEPROOM"zforest/x23y19.c",
  "southwest" : KEEPROOM"zforest/x24y17.c",
      ]));
}
