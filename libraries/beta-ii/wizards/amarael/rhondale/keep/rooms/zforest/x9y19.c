#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x8y18.c",
  "west" : KEEPROOM"zforest/x9y18.c",
  "southeast" : KEEPROOM"zforest/x10y20.c",
      ]));
}
