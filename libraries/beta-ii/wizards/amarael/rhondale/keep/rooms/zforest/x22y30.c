#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x23y29.c",
  "west" : KEEPROOM"zforest/x22y29.c",
  "east" : KEEPROOM"zforest/x22y31.c",
      ]));
}
