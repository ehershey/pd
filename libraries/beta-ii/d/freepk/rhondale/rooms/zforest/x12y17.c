#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x11y18.c",
  "northwest" : KEEPROOM"zforest/x11y16.c",
  "south" : KEEPROOM"zforest/x13y17.c",
      ]));
}
