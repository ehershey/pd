#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x14y29.c",
  "southwest" : KEEPROOM"zforest/x14y28.c",
  "north" : KEEPROOM"zforest/x12y29.c",
      ]));
}
