#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x19y17.c",
  "northeast" : KEEPROOM"zforest/x19y19.c",
  "southeast" : KEEPROOM"zforest/x21y19.c",
      ]));
}
