#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x18y13.c",
  "southwest" : KEEPROOM"zforest/x18y12.c",
  "northwest" : KEEPROOM"zforest/x16y12.c",
      ]));
}
