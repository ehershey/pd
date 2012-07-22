#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x2y11.c",
  "west" : KEEPROOM"zforest/x3y9.c",
  "southwest" : KEEPROOM"zforest/x4y9.c",
  "southeast" : KEEPROOM"zforest/x4y11.c",
      ]));
}
