#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1]) );
  set_short("%^BOLD%^%^CYAN%^The windmill.%^RESET%^");
  set_long("You are at the very top of the windmill. The roof curves inward and closes into a dome above you. The windmill can be heard creaking softly while it turns in the wind. Behind you are a set of vertical stairs that you can take to go down and out of the windmill.");
  set_items(([
    "stairs" : "The stairs lead south and down into the rest of the barn.",
    "windmill" : "You are in it.",
   ]));
  set_listen("default", "The blades of the windmill creak while they turn in the wind.");
  set_exits(([
    "down" : ROOMS"farm38"
   ]));
}
void reset() {
  if (!present("farmer")) new(MOB"farmer.c")->move(this_object());
}
