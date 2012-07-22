#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x23y12.c",
  "east" : KEEPROOM"zforest/x22y13.c",
  "northeast" : KEEPROOM"zforest/x21y13.c",
  "southwest" : KEEPROOM"zforest/x23y11.c",
      ]));
}
