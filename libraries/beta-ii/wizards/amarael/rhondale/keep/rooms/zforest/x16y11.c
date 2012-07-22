#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x17y11.c",
  "east" : KEEPROOM"zforest/x16y12.c",
  "west" : KEEPROOM"zforest/x16y10.c",
      ]));
}
