#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x22y29.c",
  "southwest" : KEEPROOM"zforest/x24y27.c",
      ]));
}
