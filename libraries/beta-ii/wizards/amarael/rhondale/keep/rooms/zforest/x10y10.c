#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x11y11.c",
  "southwest" : KEEPROOM"zforest/x11y9.c",
  "east" : KEEPROOM"zforest/x10y11.c",
  "west" : KEEPROOM"zforest/x10y9.c",
      ]));
}
