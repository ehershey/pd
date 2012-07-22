#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x4y18.c",
  "west" : KEEPROOM"zforest/x5y16.c",
  "southeast" : KEEPROOM"zforest/x6y18.c",
      ]));
}
