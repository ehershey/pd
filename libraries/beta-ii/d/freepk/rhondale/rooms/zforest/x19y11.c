#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x20y11.c",
  "northwest" : KEEPROOM"zforest/x18y10.c",
  "north" : KEEPROOM"zforest/x18y11.c",
      ]));
}
