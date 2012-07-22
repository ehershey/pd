#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x18y19.c",
  "northwest" : KEEPROOM"zforest/x18y18.c",
  "southwest" : KEEPROOM"zforest/x20y18.c",
      ]));
}
