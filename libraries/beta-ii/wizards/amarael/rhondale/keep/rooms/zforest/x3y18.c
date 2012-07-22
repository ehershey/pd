#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x2y17.c",
  "northeast" : KEEPROOM"zforest/x2y19.c",
  "south" : KEEPROOM"zforest/x4y18.c",
  "southeast" : KEEPROOM"zforest/x4y19.c",
      ]));
}
