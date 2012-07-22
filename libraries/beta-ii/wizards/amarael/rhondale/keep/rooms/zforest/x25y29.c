#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x24y30.c",
  "northwest" : KEEPROOM"zforest/x24y28.c",
  "east" : KEEPROOM"zforest/x25y30.c",
  "west" : KEEPROOM"zforest/x25y28.c",
      ]));
}
