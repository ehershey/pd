#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x11y7.c",
  "south" : KEEPROOM"zforest/x13y7.c",
  "southeast" : KEEPROOM"zforest/x13y8.c",
      ]));
}
