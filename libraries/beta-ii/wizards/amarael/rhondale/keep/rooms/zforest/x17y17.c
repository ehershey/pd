#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x17y16.c",
  "southeast" : KEEPROOM"zforest/x18y18.c",
      ]));
}
