#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x23y29.c",
  "southeast" : KEEPROOM"zforest/x25y29.c",
  "west" : KEEPROOM"zforest/x24y27.c",
      ]));
}
