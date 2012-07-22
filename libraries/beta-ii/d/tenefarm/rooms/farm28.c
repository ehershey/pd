#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The lush grass in this area is very long in this area. The river follows south at a safe distance to the west. The small dirt path leads north and south in the middle of the grass. The wind blows softly, and a general feeling of peace is in the air.");
  set_items(([
    "path" : "The path leads vertically north and south.",
    "river" : "It is to the west of here.",
   ]));
  set_listen("default", "The grass rustles gently in the wind.");
  set_exits(([
    "north" : ROOMS"farm27",
    "south" : ROOMS"farm30"
   ]));
}
