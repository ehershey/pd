#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x15y20.c",
  "northeast" : KEEPROOM"zforest/x13y21.c",
  "northwest" : KEEPROOM"zforest/x13y19.c",
  "southeast" : KEEPROOM"zforest/x15y21.c",
      ]));
}
