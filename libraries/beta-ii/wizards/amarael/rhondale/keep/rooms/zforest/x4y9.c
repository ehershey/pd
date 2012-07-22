#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x5y10.c",
  "northeast" : KEEPROOM"zforest/x3y10.c",
  "west" : KEEPROOM"zforest/x4y8.c",
      ]));
}
