#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
 "northwest" : KEEPROOM"zforest/sunstone.c",
  "southwest" : KEEPROOM"zforest/x14y10.c",
  "east" : KEEPROOM"zforest/x13y12.c",
  "west" : KEEPROOM"zforest/x13y10.c",
      ]));
}
