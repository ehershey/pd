#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "east" : KEEPROOM"zforest/x8y7.c",
  "northeast" : KEEPROOM"zforest/x7y7.c",
  "northwest" : KEEPROOM"zforest/x7y5.c",
      ]));
}
