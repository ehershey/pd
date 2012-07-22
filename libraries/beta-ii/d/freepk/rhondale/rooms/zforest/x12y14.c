#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x12y13.c",
  "northwest" : KEEPROOM"zforest/x11y13.c",
  "east" : KEEPROOM"zforest/x12y15.c",
      ]));
}
