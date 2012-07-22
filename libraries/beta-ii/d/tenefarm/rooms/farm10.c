#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The small, dirt path angles north and southwest. A little way off to the north there is a fairly large, freshly painted barn. Behind the barn a small river gently flows east. To the east the large wooden spinning blades of the top of a large mill can be seen. The blue river to the north curves south after a while and floods in the way of the path due east.");
  set_night_long("The dark path angles north and southwest. A little way off to the north there is a fairly large, freshly painted barn. Behind the barn a small river gently flows east. To the east the large black spinning blades of the top of a large windmill can be seen. The dark river to the north curves south after a while and floods in the way of the path due east.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes north and southwest.",
    "barn" : "A very large barn. It is north of your current location.",
    "river" : "It is to the north of here. If flows east behind the barn."
   ]));
  set_exits(([
    "north" : ROOMS"farm11",
    "southwest" : ROOMS"farm8"
   ]));
}
