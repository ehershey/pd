#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x20y20.c",
  "northwest" : KEEPROOM"zforest/x20y18.c",
  "south" : KEEPROOM"zforest/x22y19.c",
      ]));
}
