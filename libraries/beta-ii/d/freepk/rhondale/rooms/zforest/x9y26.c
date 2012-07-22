#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x10y27.c",
  "northwest" : KEEPROOM"zforest/x8y25.c",
  "northeast" : KEEPROOM"zforest/x8y27.c",
      ]));
}
