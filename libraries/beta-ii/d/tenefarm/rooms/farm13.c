#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The dirt path suddenly twists southwest here, and also continues east. To the north a river flows to the east. The river continues to flow east until it suddenly veers south and flows in the way of the path, flooding it. Also to the east the large wooden spinning blades of the top of a large mill can be seen.");
  set_night_long("The dark path suddenly twists southwest here, and also continues east. To the north a deep, dark river flows due east. The river continues to flow east until it suddenly turns south and flows in the way of the path, flooding it to the east. Also to the east the large black spinning blades of the top of a large mill can be seen.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes west and north.",
    "barn" : "A very large barn. It is northwest of your current location.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the east.",
    "river" : "It is to the north and to the east of here."
   ]));
  set_listen("default", "%^BLUE%^The sound of running water...");
  set_exits(([
    "southwest" : ROOMS"farm12",
    "east" : ROOMS"farm14"
   ]));
}
