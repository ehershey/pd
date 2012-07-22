#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
 set_long("A deep river flows across the path directly to the east. The river's current is slow enough to allow most civilization to cross. The path also continues west and north along the river. To the north a wide blue house can barely be seen. To the northeast on the other side of the river a mill can be seen.");
  set_night_long("The forbidding dark river consumes to the path to the east. To the northeast the large black windmill can be seen sticking out of the ground on the other side of the river. To the north a wide house can barely be seen in the distance. The path creeps back west, and follows the river to the north. From here the river flows south, out of the farm, and out of sight.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes west and north, but to the east the river swallows it whole.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the northeast.",
    "waterwheel" : "It is a watermill/windmill crossbreed. It is to the northeast.",
    "river" : "It is to the north and to the east of here.",
    "house" : "The farmer's house."
   ]));
  set_smell("default", "Eeewww, it smells like fish.");
  set_listen("default", "The river bubbles gently.");
  set_exits(([
    "north" : ROOMS"farm18",
    "east" : ROOMS"farm22",
    "west" : ROOMS"farm16"
   ]));
  add_pre_exit_function("east", "go_east");
}
void reset() {
  ::reset();
  if (!present("calf"))
    new(MOB "calf.c")->move(this_object());
}
int go_east() {
  if (this_player()->is_player()) {
    write("%^BLUE%^You jump into the cold river.");
    say("%^BLUE%^"+this_player()->query_cap_name()+" jumps into the cold river.", this_player());
    return 1;
  }
  else {
    return 0;
  }
}
