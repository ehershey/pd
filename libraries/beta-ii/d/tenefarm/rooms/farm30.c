#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The path ends abruptly when it crashes into the fence to the south. To the west the river goes right underneath the bottom of the fence and it heads into the forest. The small dirt path cuts a path through the grass to the north.");
  set_items(([
    "path" : "The path heads north.",
    "river" : "It is to the west of here.",
   ]));
  set_listen("default", "The grass rustles gently in the wind.");
  set_exits(([
    "north" : ROOMS"farm28"
   ]));
}
