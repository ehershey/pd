#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x8y15.c",
  "southwest" : KEEPROOM"zforest/x10y14.c",
      ]));
}
