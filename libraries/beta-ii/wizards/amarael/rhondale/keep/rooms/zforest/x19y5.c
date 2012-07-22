#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x20y4.c",
  "west" : KEEPROOM"zforest/x19y4.c",
  "north" : KEEPROOM"zforest/x18y5.c",
      ]));
}
