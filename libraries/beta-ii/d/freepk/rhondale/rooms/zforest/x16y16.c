#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x15y16.c",
  "west" : KEEPROOM"zforest/x16y15.c",
  "south" : KEEPROOM"zforest/x17y16.c",
      ]));
}
