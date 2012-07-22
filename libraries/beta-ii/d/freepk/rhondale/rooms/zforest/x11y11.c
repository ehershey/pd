#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
 "southwest" : KEEPROOM"zforest/sunstone.c",
  "south" : KEEPROOM"zforest/x12y11.c",
  "northeast" : KEEPROOM"zforest/x10y12.c",
  "northwest" : KEEPROOM"zforest/x10y10.c",
      ]));
}
