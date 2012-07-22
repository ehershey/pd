#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x15y4.c",
  "northeast" : KEEPROOM"zforest/x13y6.c",
  "west" : KEEPROOM"zforest/x14y4.c",
  "east" : KEEPROOM"zforest/x14y6.c",
      ]));
}
