#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x7y5.c",
  "northeast" : KEEPROOM"zforest/x5y6.c",
  "northwest" : KEEPROOM"zforest/x5y4.c",
      ]));
}
