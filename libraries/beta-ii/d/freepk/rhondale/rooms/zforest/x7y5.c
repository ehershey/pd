#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x8y5.c",
  "southeast" : KEEPROOM"zforest/x8y6.c",
  "north" : KEEPROOM"zforest/x6y5.c",
  "northeast" : KEEPROOM"zforest/x6y6.c",
      ]));
}
