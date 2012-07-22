#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x22y14.c",
  "south" : KEEPROOM"zforest/x24y15.c",
  "north" : KEEPROOM"zforest/x22y15.c",
      ]));
}
