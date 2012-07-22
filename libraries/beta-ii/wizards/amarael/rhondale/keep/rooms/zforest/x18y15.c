#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x18y14.c",
  "northeast" : KEEPROOM"zforest/x17y16.c",
  "southwest" : KEEPROOM"zforest/x19y14.c",
      ]));
}
