#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x19y20.c",
  "south" : KEEPROOM"zforest/x19y19.c",
  "north" : KEEPROOM"zforest/x17y19.c",
      ]));
}
