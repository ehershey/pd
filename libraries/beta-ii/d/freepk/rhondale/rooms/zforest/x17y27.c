#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x18y28.c",
  "south" : KEEPROOM"zforest/x18y27.c",
  "north" : KEEPROOM"zforest/x16y27.c",
      ]));
}
