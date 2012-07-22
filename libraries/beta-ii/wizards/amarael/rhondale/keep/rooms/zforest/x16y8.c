#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "east" : KEEPROOM"zforest/x16y9.c",
  "southwest" : KEEPROOM"zforest/x17y7.c",
      ]));
}
