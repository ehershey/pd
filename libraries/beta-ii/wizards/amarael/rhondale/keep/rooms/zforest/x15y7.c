#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x14y6.c",
  "southwest" : KEEPROOM"zforest/x16y6.c",
  "north" : KEEPROOM"zforest/x14y7.c",
  "south" : KEEPROOM"zforest/x16y7.c",
      ]));
}
