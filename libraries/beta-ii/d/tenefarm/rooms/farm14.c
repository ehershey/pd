#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The dirt path goes southeast for some distance, but it also goes east. To the east a river flows gently south. The river continues to flow south until it suddenly collides with the path ahead, flooding it. To the northeast the large wooden spinning blades of the top of a large mill can be seen. The farmer's house can barely be seen to the northeast.");
  set_night_long("The shadowy path goes southeast for some distance, but it also goes east. To the east a river flows gently south. The river continues to flow south until it suddenly collides with the path ahead, flooding it. To the northeast the dark spinning blades of the top of a large mill can be seen. The small black bump of the farmer's house can barely be seen to the northeast.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes west and southest.",
    "barn" : "A very large barn. It is northwest of your current location.",
      "mill" : "A large waterwheel / windmill crossbreed. It lies to the east.",
    "river" : "It is to the north and to the east of here."
   ]));
  set_listen("default", "%^BLUE%^The sound of running water...");

  set_exits(([
    "west" : ROOMS"farm13",
    "southeast" : ROOMS"farm15"
   ]));
}
