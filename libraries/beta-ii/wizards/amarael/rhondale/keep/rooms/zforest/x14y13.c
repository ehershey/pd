#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x13y13.c",
  "southwest" : KEEPROOM"zforest/x15y12.c",
  "southeast" : KEEPROOM"zforest/x15y14.c",
      ]));
}
