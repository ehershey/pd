#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x19y13.c",
  "east" : KEEPROOM"zforest/x18y15.c",
  "west" : KEEPROOM"zforest/x18y13.c",
      ]));
}
