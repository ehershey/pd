#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x16y10.c",
  "north" : KEEPROOM"zforest/x14y9.c",
  "northeast" : KEEPROOM"zforest/x14y10.c",
      ]));
}
