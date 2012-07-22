#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x17y30.c",
  "northeast" : KEEPROOM"zforest/x15y31.c",
      ]));
}
