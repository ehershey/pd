#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x17y27.c",
  "southeast" : KEEPROOM"zforest/x19y29.c",
      ]));
}
