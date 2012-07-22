#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x12y11.c",
  "northeast" : KEEPROOM"zforest/x12y13.c",
  "west" : KEEPROOM"zforest/x13y11.c",
  "east" : KEEPROOM"zforest/x13y13.c",
      ]));
}
