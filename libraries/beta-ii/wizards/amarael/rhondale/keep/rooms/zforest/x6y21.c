#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x7y22.c",
  "northwest" : KEEPROOM"zforest/x5y20.c",
  "northeast" : KEEPROOM"zforest/x5y22.c",
  "west" : KEEPROOM"zforest/x6y20.c",
      ]));
}
