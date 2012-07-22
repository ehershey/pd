#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x22y7.c",
  "northeast" : KEEPROOM"zforest/x20y8.c",
  "north" : KEEPROOM"zforest/x20y7.c",
      ]));
}
