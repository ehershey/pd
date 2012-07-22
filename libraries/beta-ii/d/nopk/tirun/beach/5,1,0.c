#include <std.h>
#include <tirunbeach.h>

inherit VMAPROOM;

void create() {
  set_map(TIRUNBEACH+"virtual");
  set_coords(5, 1, 0);
  ::create();
}
void reset() {
  ::reset();
  if(!present("sandcastle", this_object()))
    new("/d/nopk/tirun/sandcastle/item/sandcastle.c")->move(this_object());
}
