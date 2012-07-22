#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x24y8.c",
  "west" : KEEPROOM"zforest/x25y7.c",
  "east" : KEEPROOM"zforest/x25y9.c",
      ]));
}
