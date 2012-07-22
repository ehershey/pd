#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x17y13.c",
  "east" : KEEPROOM"zforest/x18y14.c",
  "northeast" : KEEPROOM"zforest/x17y14.c",
  "southwest" : KEEPROOM"zforest/x19y12.c",
      ]));
}
