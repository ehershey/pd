#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x20y12.c",
  "east" : KEEPROOM"zforest/x21y14.c",
  "southwest" : KEEPROOM"zforest/x22y12.c",
      ]));
}
