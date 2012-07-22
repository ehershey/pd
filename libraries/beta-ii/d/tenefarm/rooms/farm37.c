#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1]) );
  set_short("%^BOLD%^%^CYAN%^The windmill.%^RESET%^");
  set_long("You are at the very bottom of the windmill. The windmill looks old and worn down on the inside. You can see the inner workings of the fan high up above you. A circling stairway leads up into the windmill.");
  set_items(([
    "stairs" : "The stairs lead up into the windmill.",
    "windmill" : "You are in it.",
   ]));
  set_listen("default", "The blades of the windmill creak while they turn in the wind.");
  set_exits(([
    "up" : ROOMS"farm38",
    "out" : ROOMS"farm26",
   ]));
}
