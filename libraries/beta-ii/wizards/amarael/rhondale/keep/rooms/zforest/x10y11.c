#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x9y10.c",
  "north" : KEEPROOM"zforest/x9y11.c",
  "east" : KEEPROOM"zforest/x10y12.c",
  "west" : KEEPROOM"zforest/x10y10.c",
      ]));
}
