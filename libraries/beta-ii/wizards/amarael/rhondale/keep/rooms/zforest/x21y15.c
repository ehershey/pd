#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x22y16.c",
  "west" : KEEPROOM"zforest/x21y14.c",
  "north" : KEEPROOM"zforest/x20y15.c",
      ]));
}
