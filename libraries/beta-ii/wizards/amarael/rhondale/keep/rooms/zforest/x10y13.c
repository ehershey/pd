#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x11y13.c",
  "southeast" : KEEPROOM"zforest/x11y14.c",
  "east" : KEEPROOM"zforest/x10y14.c",
  "west" : KEEPROOM"zforest/x10y12.c",
      ]));
}
