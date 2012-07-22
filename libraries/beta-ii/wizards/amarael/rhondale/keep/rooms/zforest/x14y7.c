#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x13y6.c",
  "north" : KEEPROOM"zforest/x13y7.c",
  "south" : KEEPROOM"zforest/x15y7.c",
  "southeast" : KEEPROOM"zforest/x15y8.c",
      ]));
}
