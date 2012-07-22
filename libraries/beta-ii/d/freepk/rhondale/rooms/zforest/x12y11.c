#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x11y11.c",
 "west" : KEEPROOM"zforest/sunstone.c",
  "northeast" : KEEPROOM"zforest/x11y12.c",
  "southeast" : KEEPROOM"zforest/x13y12.c",
      ]));
}
