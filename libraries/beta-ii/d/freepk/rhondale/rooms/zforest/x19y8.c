#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x18y8.c",
  "southeast" : KEEPROOM"zforest/x20y9.c",
  "south" : KEEPROOM"zforest/x20y8.c",
      ]));
}
