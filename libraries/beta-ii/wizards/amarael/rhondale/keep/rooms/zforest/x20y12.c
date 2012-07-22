#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x21y11.c",
  "north" : KEEPROOM"zforest/x19y12.c",
  "southeast" : KEEPROOM"zforest/x21y13.c",
      ]));
}
