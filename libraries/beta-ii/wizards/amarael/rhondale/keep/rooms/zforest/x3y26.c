#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x2y27.c",
  "south" : KEEPROOM"zforest/x4y26.c",
      ]));
}