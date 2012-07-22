#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("Directly to the west a simple wooden fence stretches far north and south to keep the livestock in, but it is short enough to allow people free access. To the south-east there is a large pasture full of tall, wet, lush green grass, perfect conditions for grazing. A small dirt path comes from east of here. A large barn can be seen due north-east of here, and behind that a small stream can be seen flowing gently east.");
  set_night_long("Directly west of here a long intimidating wooden fence stretches like a black snake across the ground to the north and south. The dark rows of grass blows gently back and forth in the wind to the south-east. The soft wooshing of a steam can be heard somewhere to the north, but pin-pointing it proves impossible. A large dark house-shaped shadow looms to the north-east.");
  set_listen("default", "Soft, contented mooes can be heard from the south.");
  set_items(([
    "fence" : "A wooden fence.",
    "pasture" : "To the south-east. It is full of wonderful grass.",
    "path" : "A small dirt path to make walking easier. It goes east.",
    "barn" : "A very large barn. It is north-east of your current location.",
    "shadow" : "Upon closer examination, you notice it is a barn.",
    "stream" : "It is to the north of here. If flows west and east behind the barn."
   ]));
  set_exits(([
    "west" : ROOMS"farm1",
    "east" : ROOMS"farm7"
   ]));
  add_pre_exit_function("west", "go_west");
}
void reset() {
  ::reset();
  if (sizeof(children(MOB"angbull.c"))==0)
    new(MOB "angbull.c")->move(this_object());
}
int go_west() {
  if(!this_player()->is_player()) return 0;
  write("%^ORANGE%^You place one hand on the top of the fence and heave yourself over.");
  say(this_player()->query_name()+" places one hand on the top of the fence and jumps over.", this_player());
  return 1;
}
