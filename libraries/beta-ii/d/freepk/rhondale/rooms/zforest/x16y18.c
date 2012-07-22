#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "south" : KEEPROOM"zforest/x17y18.c",
  "northeast" : KEEPROOM"zforest/x15y19.c",
  "northwest" : KEEPROOM"zforest/x15y17.c",
      ]));
}
