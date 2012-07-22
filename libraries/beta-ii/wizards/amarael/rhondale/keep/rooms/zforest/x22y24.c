#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x21y24.c",
  "east" : KEEPROOM"zforest/x22y25.c",
  "southwest" : KEEPROOM"zforest/x23y23.c",
  "southeast" : KEEPROOM"zforest/x23y25.c",
      ]));
}
