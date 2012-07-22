#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x9y15.c",
  "northwest" : KEEPROOM"zforest/x9y13.c",
  "west" : KEEPROOM"zforest/x10y13.c",
      ]));
}
