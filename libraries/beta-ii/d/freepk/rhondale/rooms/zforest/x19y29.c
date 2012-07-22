#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x18y30.c",
  "northwest" : KEEPROOM"zforest/x18y28.c",
  "south" : KEEPROOM"zforest/x20y29.c",
      ]));
}
