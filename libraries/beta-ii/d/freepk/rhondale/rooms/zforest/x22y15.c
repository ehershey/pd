#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x23y15.c",
  "northwest" : KEEPROOM"zforest/x21y14.c",
  "southeast" : KEEPROOM"zforest/x23y16.c",
      ]));
}
