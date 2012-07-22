#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x23y9.c",
  "north" : KEEPROOM"zforest/x21y9.c",
      ]));
}
