#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x5y14.c",
  "south" : KEEPROOM"zforest/x5y15.c",
  "north" : KEEPROOM"zforest/x3y15.c",
      ]));
}
