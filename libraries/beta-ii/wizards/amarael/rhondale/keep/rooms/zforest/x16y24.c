#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x17y25.c",
  "southwest" : KEEPROOM"zforest/x17y23.c",
  "north" : KEEPROOM"zforest/x15y24.c",
      ]));
}
