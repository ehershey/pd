#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x21y7.c",
  "southwest" : KEEPROOM"zforest/x21y6.c",
  "northwest" : KEEPROOM"zforest/x19y6.c",
      ]));
}
