#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x21y8.c",
  "northwest" : KEEPROOM"zforest/x19y8.c",
  "south" : KEEPROOM"zforest/x21y9.c",
      ]));
}
