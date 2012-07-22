#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x23y16.c",
  "east" : KEEPROOM"zforest/x24y17.c",
  "south" : KEEPROOM"zforest/x25y16.c",
      ]));
}
