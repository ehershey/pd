#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x15y21.c",
  "southwest" : KEEPROOM"zforest/x17y21.c",
  "east" : KEEPROOM"zforest/x16y23.c",
      ]));
}
