#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x1y16.c",
  "southwest" : KEEPROOM"zforest/x3y15.c",
  "northeast" : KEEPROOM"zforest/x1y17.c",
      ]));
}
