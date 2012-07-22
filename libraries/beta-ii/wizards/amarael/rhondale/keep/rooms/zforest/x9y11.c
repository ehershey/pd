#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x10y11.c",
  "northwest" : KEEPROOM"zforest/x8y10.c",
  "north" : KEEPROOM"zforest/x8y11.c",
      ]));
}
