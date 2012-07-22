#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x2y23.c",
  "southwest" : KEEPROOM"zforest/x3y23.c",
  "southeast" : KEEPROOM"zforest/x3y25.c",
      ]));
}
