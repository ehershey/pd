#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The path turns away from the river and heads farther down south. The lush green grass grows out even more around here. The river follows south at a safe distance to the west. The wind blows softly, and a general feeling of peace is in the air.");
  set_items(([
    "path" : "The path leads northwest and south.",
    "river" : "It is to the west of here.",
   ]));
  set_listen("default", "The grass rustles gently in the wind.");
  set_exits(([
    "northwest" : ROOMS"farm23",
    "south" : ROOMS"farm28",
   ]));
}
