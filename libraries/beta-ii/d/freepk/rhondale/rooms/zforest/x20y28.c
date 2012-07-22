#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x19y28.c",
  "west" : KEEPROOM"zforest/x20y27.c",
  "south" : KEEPROOM"zforest/x21y28.c",
      ]));
}
