#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x13y22.c",
  "northeast" : KEEPROOM"zforest/x11y22.c",
  "west" : KEEPROOM"zforest/x12y20.c",
      ]));
}
