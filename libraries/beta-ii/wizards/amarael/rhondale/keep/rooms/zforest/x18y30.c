#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x17y30.c",
  "northeast" : KEEPROOM"zforest/x17y31.c",
  "west" : KEEPROOM"zforest/x18y29.c",
  "southwest" : KEEPROOM"zforest/x19y29.c",
      ]));
}
