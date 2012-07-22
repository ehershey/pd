#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x14y30.c",
  "southwest" : KEEPROOM"zforest/x16y30.c",
  "south" : KEEPROOM"zforest/x16y31.c",
      ]));
}
