#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "east" : KEEPROOM"zforest/x20y28.c",
  "southwest" : KEEPROOM"zforest/x21y26.c",
      ]));
}
