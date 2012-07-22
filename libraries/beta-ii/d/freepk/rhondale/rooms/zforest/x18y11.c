#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x19y11.c",
  "southeast" : KEEPROOM"zforest/x19y12.c",
  "north" : KEEPROOM"zforest/x17y11.c",
      ]));
}
