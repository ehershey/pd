#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x21y3.c",
  "northeast" : KEEPROOM"zforest/x19y4.c",
  "north" : KEEPROOM"zforest/x19y3.c",
      ]));
}
