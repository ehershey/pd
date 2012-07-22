#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "northwest" : KEEPROOM"zforest/x15y8.c",
  "south" : KEEPROOM"zforest/x17y9.c",
  "west" : KEEPROOM"zforest/x16y8.c",
  "east" : KEEPROOM"zforest/x16y10.c",
      ]));
}
