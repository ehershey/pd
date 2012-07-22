#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x15y9.c",
  "northeast" : KEEPROOM"zforest/x15y11.c",
  "west" : KEEPROOM"zforest/x16y9.c",
  "east" : KEEPROOM"zforest/x16y11.c",
      ]));
}
