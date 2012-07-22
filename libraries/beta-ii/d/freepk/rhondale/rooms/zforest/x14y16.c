#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x14y15.c",
  "southeast" : KEEPROOM"zforest/x15y17.c",
      ]));
}
