#include <std.h>
#include <tirunbeach.h>

inherit VMAPROOM;

void create() {
  set_map(TIRUNBEACH+"virtual");
  set_coords(7, 4, 0);
  ::create();
}
void reset() {
 ::reset();
   if (!present("log"))
      new("/d/nopk/tirun/obj/misc/log")->move(this_object());
}
