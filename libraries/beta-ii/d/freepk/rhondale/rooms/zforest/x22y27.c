#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x21y28.c",
  "southwest" : KEEPROOM"zforest/x23y26.c",
      ]));
}
