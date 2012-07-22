#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x14y13.c",
  "west" : KEEPROOM"zforest/x13y12.c",
  "east" : KEEPROOM"zforest/x13y14.c",
      ]));
}
