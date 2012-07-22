#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1]) );
  set_short("%^BOLD%^%^CYAN%^The windmill.%^RESET%^");
  set_long("The windmill's stairs creak and moan, and the whole tower seems to sigh over the force of the wind buffeting its walls.");
  set_items(([
    "stairs" : "you are on them.",
    "windmill" : "You are in it.",
   ]));
  set_listen("default", "The blades of the windmill creak while they turn in the wind.");
  set_exits(([
    "down" : ROOMS"farm37",
    "up" : ROOMS"farm39",
   ]));
}
