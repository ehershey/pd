#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x6y8.c",
  "southeast" : KEEPROOM"zforest/x6y9.c",
  "east" : KEEPROOM"zforest/x5y9.c",
  "west" : KEEPROOM"zforest/x5y7.c",
      ]));
}
