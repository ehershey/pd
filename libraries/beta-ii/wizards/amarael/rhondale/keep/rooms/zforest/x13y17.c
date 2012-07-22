#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x12y17.c",
  "east" : KEEPROOM"zforest/x13y18.c",
  "west" : KEEPROOM"zforest/x13y16.c",
  "southeast" : KEEPROOM"zforest/x14y18.c",
      ]));
}
