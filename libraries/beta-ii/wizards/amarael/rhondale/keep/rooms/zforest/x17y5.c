#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x18y5.c",
  "northwest" : KEEPROOM"zforest/x16y4.c",
  "northeast" : KEEPROOM"zforest/x16y6.c",
      ]));
}
