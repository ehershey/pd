#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x9y30.c",
  "north" : KEEPROOM"zforest/x7y31.c",
  "west" : KEEPROOM"zforest/x8y30.c",
      ]));
}
