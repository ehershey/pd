#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x9y28.c",
  "east" : KEEPROOM"zforest/x8y30.c",
      ]));
}
