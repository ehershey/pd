#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x15y9.c",
  "northwest" : KEEPROOM"zforest/x13y8.c",
  "northeast" : KEEPROOM"zforest/x13y10.c",
      ]));
}
