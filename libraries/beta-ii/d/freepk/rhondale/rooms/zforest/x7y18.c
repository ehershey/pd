#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x6y18.c",
  "northwest" : KEEPROOM"zforest/x6y17.c",
  "east" : KEEPROOM"zforest/x7y19.c",
      ]));
}
