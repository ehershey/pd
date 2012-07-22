#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x25y14.c",
  "northwest" : KEEPROOM"zforest/x23y12.c",
  "northeast" : KEEPROOM"zforest/x23y14.c",
  "west" : KEEPROOM"zforest/x24y12.c",
      ]));
}
