#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x23y22.c",
  "northeast" : KEEPROOM"zforest/x21y23.c",
  "northwest" : KEEPROOM"zforest/x21y21.c",
      ]));
}
