#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x12y21.c",
  "west" : KEEPROOM"zforest/x13y21.c",
  "southeast" : KEEPROOM"zforest/x14y23.c",
      ]));
}
