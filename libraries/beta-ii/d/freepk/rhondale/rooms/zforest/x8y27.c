#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x7y26.c",
  "north" : KEEPROOM"zforest/x7y27.c",
  "southwest" : KEEPROOM"zforest/x9y26.c",
  "south" : KEEPROOM"zforest/x9y27.c",
      ]));
}
