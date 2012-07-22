#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x21y3.c",
  "east" : KEEPROOM"zforest/x22y4.c",
  "southeast" : KEEPROOM"zforest/x23y4.c",
  "south" : KEEPROOM"zforest/x23y3.c",
      ]));
}
