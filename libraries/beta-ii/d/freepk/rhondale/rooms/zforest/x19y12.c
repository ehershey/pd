#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x18y11.c",
  "north" : KEEPROOM"zforest/x18y12.c",
  "northeast" : KEEPROOM"zforest/x18y13.c",
  "east" : KEEPROOM"zforest/x19y13.c",
  "south" : KEEPROOM"zforest/x20y12.c",
      ]));
}
