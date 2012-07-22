#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x9y28.c",
  "north" : KEEPROOM"zforest/x9y27.c",
  "northwest" : KEEPROOM"zforest/x9y26.c",
  "west" : KEEPROOM"zforest/x10y26.c",
  "southeast" : KEEPROOM"zforest/x11y28.c",
      ]));
}
