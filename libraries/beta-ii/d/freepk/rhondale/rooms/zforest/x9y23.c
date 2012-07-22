#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x8y24.c",
  "northwest" : KEEPROOM"zforest/x8y22.c",
  "west" : KEEPROOM"zforest/x9y22.c",
  "east" : KEEPROOM"zforest/x9y24.c",
      ]));
}
