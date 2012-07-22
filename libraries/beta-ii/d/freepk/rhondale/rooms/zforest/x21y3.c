#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x20y4.c",
  "north" : KEEPROOM"zforest/x20y3.c",
  "south" : KEEPROOM"zforest/x22y3.c",
      ]));
}
