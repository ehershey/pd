#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x19y20.c",
  "southwest" : KEEPROOM"zforest/x21y19.c",
      ]));
}
