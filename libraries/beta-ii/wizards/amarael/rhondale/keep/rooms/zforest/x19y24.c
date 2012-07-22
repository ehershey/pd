#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x18y24.c",
  "southwest" : KEEPROOM"zforest/x20y23.c",
      ]));
}