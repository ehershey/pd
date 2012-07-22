#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "north" : KEEPROOM"zforest/x16y7.c",
  "northeast" : KEEPROOM"zforest/x16y8.c",
  "southeast" : KEEPROOM"zforest/x18y8.c",
  "southwest" : KEEPROOM"zforest/x18y6.c",
  "north" : KEEPROOM"zforest/x16y7.c",
  "southeast" : KEEPROOM"zforest/x18y8.c",
  "southwest" : KEEPROOM"zforest/x18y6.c",
      ]));
}
