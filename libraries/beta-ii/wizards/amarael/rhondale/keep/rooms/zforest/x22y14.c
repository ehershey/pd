#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "west" : KEEPROOM"zforest/x22y13.c",
  "southeast" : KEEPROOM"zforest/x23y15.c",
  "south" : KEEPROOM"zforest/x23y14.c",
      ]));
}
