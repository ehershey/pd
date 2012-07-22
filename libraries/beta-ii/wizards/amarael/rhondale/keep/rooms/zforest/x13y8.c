#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southeast" : KEEPROOM"zforest/x14y9.c",
  "north" : KEEPROOM"zforest/x12y8.c",
  "northwest" : KEEPROOM"zforest/x12y7.c",
      ]));
}
