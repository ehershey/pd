
#include <std.h>
#include <ridarin.h>

inherit VIRTUALMAP;

void create() {
  set_mapfile(RIDARIN+"map");
  set_descfile(RIDARIN+"descs");
  set_compact(2);
  ::create();
}

