#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "east" : KEEPROOM"zforest/x14y16.c",
  "northwest" : KEEPROOM"zforest/x13y14.c",
  "southeast" : KEEPROOM"zforest/x15y16.c",
      ]));
}
