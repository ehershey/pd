#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x13y25.c",
  "west" : KEEPROOM"zforest/x14y24.c",
  "southwest" : KEEPROOM"zforest/x15y24.c",
      ]));
}
