#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x10y27.c",
  "west" : KEEPROOM"zforest/x11y27.c",
  "southwest" : KEEPROOM"zforest/x12y27.c",
  "southeast" : KEEPROOM"zforest/x12y29.c",
      ]));
}
