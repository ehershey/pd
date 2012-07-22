#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x16y14.c",
  "northeast" : KEEPROOM"zforest/x16y15.c",
  "southwest" : KEEPROOM"zforest/x18y13.c",
      ]));
}
