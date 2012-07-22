#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x6y30.c",
  "south" : KEEPROOM"zforest/x8y31.c",
      ]));
}
