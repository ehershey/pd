#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x12y6.c",
  "northwest" : KEEPROOM"zforest/x12y5.c",
  "southeast" : KEEPROOM"zforest/x14y7.c",
  "southwest" : KEEPROOM"zforest/x14y5.c",
      ]));
}
