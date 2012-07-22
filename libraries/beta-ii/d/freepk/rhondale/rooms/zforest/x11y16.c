#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northeast" : KEEPROOM"zforest/x10y17.c",
  "west" : KEEPROOM"zforest/x11y15.c",
  "southeast" : KEEPROOM"zforest/x12y17.c",
      ]));
}
