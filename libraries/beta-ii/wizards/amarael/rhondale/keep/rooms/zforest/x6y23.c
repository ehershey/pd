#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x7y24.c",
  "northwest" : KEEPROOM"zforest/x5y22.c",
  "east" : KEEPROOM"zforest/x6y24.c",
      ]));
}
