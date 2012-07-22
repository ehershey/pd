#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x17y27.c",
  "northwest" : KEEPROOM"zforest/x17y26.c",
  "southeast" : KEEPROOM"zforest/x19y28.c",
  "southwest" : KEEPROOM"zforest/x19y26.c",
      ]));
}
