#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x15y23.c",
  "east" : KEEPROOM"zforest/x14y25.c",
  "west" : KEEPROOM"zforest/x14y23.c",
      ]));
}
