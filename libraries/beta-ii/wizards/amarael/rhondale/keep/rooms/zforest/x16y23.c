#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x17y23.c",
  "southwest" : KEEPROOM"zforest/x17y22.c",
  "west" : KEEPROOM"zforest/x16y22.c",
  "north" : KEEPROOM"zforest/x15y23.c",
      ]));
}
