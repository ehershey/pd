#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x25y8.c",
  "northwest" : KEEPROOM"zforest/x23y7.c",
  "northeast" : KEEPROOM"zforest/x23y9.c",
      ]));
}
