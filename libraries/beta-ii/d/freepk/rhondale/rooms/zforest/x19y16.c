#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x20y15.c",
  "east" : KEEPROOM"zforest/x19y17.c",
      ]));
}
