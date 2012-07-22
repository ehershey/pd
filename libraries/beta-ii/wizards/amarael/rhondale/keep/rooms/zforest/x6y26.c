#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x5y25.c",
  "north" : KEEPROOM"zforest/x5y26.c",
  "east" : KEEPROOM"zforest/x6y27.c",
  "south" : KEEPROOM"zforest/x7y26.c",
      ]));
}
