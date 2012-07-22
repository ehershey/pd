#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x3y8.c",
  "east" : KEEPROOM"zforest/x3y10.c",
      ]));
}
