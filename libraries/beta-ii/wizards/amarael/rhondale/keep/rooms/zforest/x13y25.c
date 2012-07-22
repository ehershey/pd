#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x14y26.c",
  "east" : KEEPROOM"zforest/x13y26.c",
  "north" : KEEPROOM"zforest/x12y25.c",
  "south" : KEEPROOM"zforest/x14y25.c",
      ]));
}
