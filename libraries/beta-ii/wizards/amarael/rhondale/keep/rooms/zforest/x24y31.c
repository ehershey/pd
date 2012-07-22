#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x23y31.c",
  "west" : KEEPROOM"zforest/x24y30.c",
  "southwest" : KEEPROOM"zforest/x25y30.c",
      ]));
}
