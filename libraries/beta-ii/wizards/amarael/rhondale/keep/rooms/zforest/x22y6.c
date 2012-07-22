#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x23y5.c",
  "north" : KEEPROOM"zforest/x21y6.c",
      ]));
}
