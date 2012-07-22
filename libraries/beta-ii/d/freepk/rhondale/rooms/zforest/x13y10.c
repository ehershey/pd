#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
 "north" : KEEPROOM"zforest/sunstone.c",
  "southwest" : KEEPROOM"zforest/x14y9.c",
  "east" : KEEPROOM"zforest/x13y11.c",
      ]));
}
