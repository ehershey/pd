#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x21y23.c",
  "northeast" : KEEPROOM"zforest/x19y24.c",
  "northwest" : KEEPROOM"zforest/x19y22.c",
      ]));
}
