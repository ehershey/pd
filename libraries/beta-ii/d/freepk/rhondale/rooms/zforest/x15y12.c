#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x14y13.c",
  "west" : KEEPROOM"zforest/x15y11.c",
  "southeast" : KEEPROOM"zforest/x16y13.c",
      ]));
}
