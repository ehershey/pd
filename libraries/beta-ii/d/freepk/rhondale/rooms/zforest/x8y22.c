#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x7y22.c",
  "southwest" : KEEPROOM"zforest/x9y21.c",
  "southeast" : KEEPROOM"zforest/x9y23.c",
      ]));
}
