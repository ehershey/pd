#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x7y16.c",
  "north" : KEEPROOM"zforest/x7y15.c",
  "south" : KEEPROOM"zforest/x9y15.c",
      ]));
}
