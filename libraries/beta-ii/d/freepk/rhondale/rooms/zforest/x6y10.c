#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x7y10.c",
  "northwest" : KEEPROOM"zforest/x5y9.c",
  "southeast" : KEEPROOM"zforest/x7y11.c",
      ]));
}
