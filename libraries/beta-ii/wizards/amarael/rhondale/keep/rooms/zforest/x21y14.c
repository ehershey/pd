#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x20y14.c",
  "east" : KEEPROOM"zforest/x21y15.c",
  "west" : KEEPROOM"zforest/x21y13.c",
  "southeast" : KEEPROOM"zforest/x22y15.c",
      ]));
}
