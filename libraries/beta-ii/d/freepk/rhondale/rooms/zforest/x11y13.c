#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x12y14.c",
  "north" : KEEPROOM"zforest/x10y13.c",
  "west" : KEEPROOM"zforest/x11y12.c",
      ]));
}
