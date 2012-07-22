#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The dirt path goes northwest for some distance, but it also goes east. To the east a river suddenly collides with the path ahead, completly submerging it. To the northeast the large wooden spinning blades of the top of a large mill can be seen. The farmer's house can barely be seen to the northeast as well.");
  set_night_long("The shadowy path goes northwest for some distance, but it also goes east. To the east a river suddenly collides with the path ahead, plunging it into complete darkness. To the northeast the dark spinning blades of the top of a large mill can be seen. The small black bump of the farmer's house can barely be seen to the northeast as well.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes northwest and east.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the east.",
    "river" : "It is to the north and to the east of here.",
    "house" : "The farmer's house."
   ]));
  set_smell("river", "eeewww, fish.");
  set_smell("default", "%^GREEN%^Freshly cut grass.");
  set_exits(([
    "northwest" : ROOMS"farm15",
    "east" : ROOMS"farm17"
   ]));
}
