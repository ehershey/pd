#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x4y16.c",
  "east" : KEEPROOM"zforest/x5y17.c",
  "southeast" : KEEPROOM"zforest/x6y17.c",
      ]));
}
