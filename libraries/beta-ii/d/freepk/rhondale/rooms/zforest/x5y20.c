#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x4y19.c",
  "west" : KEEPROOM"zforest/x5y19.c",
  "southeast" : KEEPROOM"zforest/x6y21.c",
      ]));
}
