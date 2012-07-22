#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
 "southeast" : KEEPROOM"zforest/sunstone.c",
  "northeast" : KEEPROOM"zforest/x10y10.c",
  "southwest" : KEEPROOM"zforest/x12y8.c",
      ]));
}
