#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x21y30.c",
  "west" : KEEPROOM"zforest/x22y30.c",
  "south" : KEEPROOM"zforest/x23y31.c",
      ]));
}
