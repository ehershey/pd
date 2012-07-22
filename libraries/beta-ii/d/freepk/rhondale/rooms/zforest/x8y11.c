#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x9y12.c",
  "south" : KEEPROOM"zforest/x9y11.c",
  "north" : KEEPROOM"zforest/x7y11.c",
      ]));
}
