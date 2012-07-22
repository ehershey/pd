#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x5y15.c",
  "southwest" : KEEPROOM"zforest/x7y14.c",
  "south" : KEEPROOM"zforest/x7y15.c",
      ]));
}
