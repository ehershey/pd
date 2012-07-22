#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1]) );
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("To the south there is a large pasture full of tall, wet, lush green grass, perfect conditions for grazing. A small dirt path comes from the south of here, and continues east and west. A large barn can be seen due north-east of here, and behind that a small stream can be seen flowing gently east.");
  set_night_long("The dark rows of grass blows gently back and forth in the wind to the south. The soft wooshing of a stream can be heard somewhere to the north, but pin-pointing it proves impossible. A large dark barn looms to the north-east.");
  set_listen("default", "The gentle whoosing of the river.");
  set_smell("default", "Fresh, crisp air, delivered on a chill gust of wind");
  set_items(([
    "grass" : "The grass to the south sways gently back and forth in the wind...",
      "pasture" : "To the south. It is full of wonderful grass.",
    "path" : "A small dirt path to make walking easier. It goes south, east, and west.",
    "barn" : "A very large barn. It is north-east of your current location.",
    "stream" : "It is to the north of here. If flows west and east behind the barn."
   ]));
  set_exits(([
    "west" : ROOMS"farm2",
    "east" : ROOMS"farm8",
    "south" : ROOMS"farm3"
   ]));
}
