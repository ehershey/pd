#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x21y19.c",
  "northeast" : KEEPROOM"zforest/x21y20.c",
  "southeast" : KEEPROOM"zforest/x23y20.c",
      ]));
}
