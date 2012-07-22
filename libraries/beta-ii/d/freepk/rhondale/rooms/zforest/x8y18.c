#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x9y17.c",
  "southeast" : KEEPROOM"zforest/x9y19.c",
  "northwest" : KEEPROOM"zforest/x7y17.c",
  "east" : KEEPROOM"zforest/x8y19.c",
      ]));
}
