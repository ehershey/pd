#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x9y23.c",
  "southeast" : KEEPROOM"zforest/x10y25.c",
      ]));
}
