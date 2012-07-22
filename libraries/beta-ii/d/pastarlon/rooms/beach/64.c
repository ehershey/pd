#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "roads/63.c",
    "southeast" : ROOMS + "docks/84.c",
    "southwest" : ROOMS + "beach/80.c",
    "west" : ROOMS + "beach/65.c",
  ]));
}
