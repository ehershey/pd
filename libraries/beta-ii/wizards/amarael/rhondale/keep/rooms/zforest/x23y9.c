#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x22y8.c",
  "north" : KEEPROOM"zforest/x22y9.c",
  "northeast" : KEEPROOM"zforest/x22y10.c",
  "southwest" : KEEPROOM"zforest/x24y8.c",
      ]));
}
