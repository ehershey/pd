#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x16y16.c",
  "southwest" : KEEPROOM"zforest/x18y15.c",
  "east" : KEEPROOM"zforest/x17y17.c",
      ]));
}
