#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x25y28.c",
  "east" : KEEPROOM"zforest/x24y28.c",
  "northeast" : KEEPROOM"zforest/x23y28.c",
  "northeast" : KEEPROOM"zforest/x23y28.c",
  "west" : KEEPROOM"zforest/x24y26.c",
      ]));
}
