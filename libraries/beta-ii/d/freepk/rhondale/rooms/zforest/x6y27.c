#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x7y27.c",
  "north" : KEEPROOM"zforest/x5y27.c",
  "west" : KEEPROOM"zforest/x6y26.c",
  "east" : KEEPROOM"zforest/x6y28.c",
      ]));
}
