#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x16y23.c",
  "south" : KEEPROOM"zforest/x18y22.c",
  "southwest" : KEEPROOM"zforest/x18y21.c",
      ]));
}
