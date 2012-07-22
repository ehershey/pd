#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The path curves away from the river to the west. The river flows from the north, down to a mill, and then flows to the southwest until it crosses the path to the southwest and swallows it whole.");
  set_night_long("The dark and silent path curves away from the deep river to the west. The river flows from the north, down to a mill, and then flows to the southwest until it crosses the path to the southwest and savagley swallows it whole.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes southwest, and then turns east.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the northeast.",
    "waterwheel" : "It is a watermill/windmill crossbreed. It is to the northeast.",
    "river" : "It is to the west of here, the path turns away from it.",
    "house" : "The farmer's house."
   ]));
  set_smell("default", "It smells like freshly cut grass here.");
  set_listen("default", "The gentle rushing of the river can be heard.");
  set_exits(([
    "east" : ROOMS"farm25",
    "southwest" : ROOMS"farm23"
   ]));
}
