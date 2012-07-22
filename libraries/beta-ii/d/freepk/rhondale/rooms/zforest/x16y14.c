#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x15y14.c",
  "west" : KEEPROOM"zforest/x16y13.c",
  "south" : KEEPROOM"zforest/x17y14.c",
      ]));
}
