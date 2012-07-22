#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x24y10.c",
  "east" : KEEPROOM"zforest/x23y11.c",
  "north" : KEEPROOM"zforest/x22y10.c",
      ]));
}
