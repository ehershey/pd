#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x6y23.c",
  "southwest" : KEEPROOM"zforest/x6y21.c",
  "north" : KEEPROOM"zforest/x4y22.c",
      ]));
}
