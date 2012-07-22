#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x23y10.c",
  "northeast" : KEEPROOM"zforest/x22y12.c",
  "southeast" : KEEPROOM"zforest/x24y12.c",
      ]));
}
