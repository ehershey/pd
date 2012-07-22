#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("To the west the path is swallowed up by a very deep river. The path continues northeast and southeast. To the northeast the path goes on for a while until it stops at a mill. To the southeast the path follows along sluggishly until it meets the fence, where it terminates suddenly. To the northwest a wide house can be seen across the river.");
  set_night_long("To the west the path is swallowed up by a very dark and deep river. The path continues northeast and southeast. To the northeast the path goes on for a while until it stops at a mill. To the southeast the path follows along sluggishly until it meets the fence, where it suddenly dies. To the northwest a wide, spooky house can be seen across the river.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes west southeast, and northeast, but to the west the river swallows it whole.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the northeast.",
    "waterwheel" : "It is a watermill/windmill crossbreed. It is to the northeast.",
    "river" : "It is to the west of here.",
    "house" : "The farmer's house."
   ]));
  set_smell("default", "Eeewww, it smells like fish.");
  set_listen("default", "The river bubbles gently.");
  set_exits(([
    "northeast" : ROOMS"farm24",
    "west" : ROOMS"farm22",
    "southeast" : ROOMS"farm27"
   ]));
  add_pre_exit_function("west", "go_west");
}
int go_west() {
  if (this_player()->is_player()) {
    write("%^BLUE%^You jump into the cold river.");
    say("%^BLUE%^"+this_player()->query_cap_name()+" jumps into the cold river.", this_player());
    return 1;
  }
  else {
    return 0;
  }
}
