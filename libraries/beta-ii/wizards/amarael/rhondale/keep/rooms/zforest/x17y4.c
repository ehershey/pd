#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x16y3.c",
  "south" : KEEPROOM"zforest/x18y4.c",
      ]));
}
