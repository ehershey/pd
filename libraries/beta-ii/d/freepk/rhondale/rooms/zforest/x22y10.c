#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x23y9.c",
  "south" : KEEPROOM"zforest/x23y10.c",
  "north" : KEEPROOM"zforest/x21y10.c",
  "northeast" : KEEPROOM"zforest/x21y11.c",
      ]));
}
