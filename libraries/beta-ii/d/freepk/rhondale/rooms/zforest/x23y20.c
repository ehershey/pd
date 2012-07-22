#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x22y19.c",
  "southeast" : KEEPROOM"zforest/x24y21.c",
  "west" : KEEPROOM"zforest/x23y19.c",
      ]));
}
