#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x17y18.c",
  "northwest" : KEEPROOM"zforest/x17y17.c",
  "southeast" : KEEPROOM"zforest/x19y19.c",
      ]));
}
