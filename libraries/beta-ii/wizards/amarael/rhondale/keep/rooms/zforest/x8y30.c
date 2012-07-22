#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x7y29.c",
  "west" : KEEPROOM"zforest/x8y29.c",
  "east" : KEEPROOM"zforest/x8y31.c",
      ]));
}
