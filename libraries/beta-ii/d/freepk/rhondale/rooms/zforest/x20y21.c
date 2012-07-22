#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x19y21.c",
  "south" : KEEPROOM"zforest/x21y21.c",
  "southwest" : KEEPROOM"zforest/x21y20.c",
      ]));
}
