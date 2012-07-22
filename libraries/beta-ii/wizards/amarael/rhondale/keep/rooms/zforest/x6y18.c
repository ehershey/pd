#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x7y18.c",
  "northwest" : KEEPROOM"zforest/x5y17.c",
  "northeast" : KEEPROOM"zforest/x5y19.c",
      ]));
}
