#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x11y27.c",
  "west" : KEEPROOM"zforest/x10y25.c",
  "east" : KEEPROOM"zforest/x10y27.c",
      ]));
}
