#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x18y19.c",
  "north" : KEEPROOM"zforest/x18y20.c",
  "south" : KEEPROOM"zforest/x20y20.c",
      ]));
}
