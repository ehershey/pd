#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
set_long("The path follows the river to the east closely. Across the river to the east the moving objects of a mill can be seen. To the north the path curves northeast and continues until it reaches it farmer's house, where it waits expectantly. To the southeast the river crosses the path and swallows it whole.");
 set_night_long("The path follows the river to the east closely, as if afraid to leave it and wander off into the cold, dark night. Across the river to the east the dark moving objects of a mill can be seen. To the north the path curves northeast and continues until it reaches it farmer's house, where it waits expectantly. To the southeast the river crosses the path and swallows it whole.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes south and north.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the east, across the river.",
    "waterwheel" : "It is a watermill/windmill crossbreed. It is to the east, across the river",
    "river" : "It is to the east of here.",
    "house" : "The farmer's house."
   ]));
  set_smell("default", "It smells like freshly cut grass here.");
  set_listen("default", "The gentle rushing of the river can be heard.");
  set_exits(([
    "north" : ROOMS"farm19",
    "south" : ROOMS"farm17"
   ]));
}
