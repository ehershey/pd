#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "east" : KEEPROOM"zforest/x12y14.c",
  "southwest" : KEEPROOM"zforest/x13y12.c",
      ]));
}
