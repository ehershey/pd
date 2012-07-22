#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x9y17.c",
  "northeast" : KEEPROOM"zforest/x9y18.c",
  "southwest" : KEEPROOM"zforest/x11y16.c",
      ]));
}
