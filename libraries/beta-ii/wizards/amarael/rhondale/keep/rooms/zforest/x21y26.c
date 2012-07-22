#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x20y26.c",
  "northeast" : KEEPROOM"zforest/x20y27.c",
  "southwest" : KEEPROOM"zforest/x22y25.c",
      ]));
}
