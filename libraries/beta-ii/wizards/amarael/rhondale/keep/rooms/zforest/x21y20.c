#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x20y21.c",
  "southwest" : KEEPROOM"zforest/x22y19.c",
      ]));
}