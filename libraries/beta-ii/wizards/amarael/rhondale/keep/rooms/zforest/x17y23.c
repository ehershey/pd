#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x18y24.c",
  "northeast" : KEEPROOM"zforest/x16y24.c",
  "north" : KEEPROOM"zforest/x16y23.c",
      ]));
}
