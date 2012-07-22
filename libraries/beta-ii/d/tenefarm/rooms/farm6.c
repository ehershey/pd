#include <std.h>
#include <wildfire.h>
inherit ROOMS"grazeable";
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("Tall, plump, luscious green grass grows from the ground plentifully here. The grass gently sways back and forth with a soft, calming, rustling sound. Directly to the north a small path goes west and east. The grass is so tall that is blocks out the view from everything else. To the west the patch of grass ends and turns into well cut grass. The pasture continues south, west, and southwest.");
  set_night_long("Tall fat dark grass grows from all over the ground here. The dark blades gently sway back and forth in the wind. Directly to the north a small, dark path creeps west and east. The grass is so tall that is blocks out the view from everything else. To the west the patch of grass ends and turns into well cut grass. The pasture continues north, west, and northwest.");
  set_smell("default", "The overwhelming scent of the best grass you ever smelled.");
  set_listen("default", "Excited and contented moos can be heard all around.");
  set_items(([
    "pasture" : "You are in it. It is full of wonderful grass.",
    "barn" : "A very large barn. It is north-east of your current location.",
    "stream" : "It is far to the north of here. If flows east behind the barn.",
    "grass" : "It is very large and delicious."
   ]));
  set_exits(([
    "west" : ROOMS"farm3",
    "south" : ROOMS"farm5",
    "southwest" : ROOMS"farm4",
   ]));
}
void reset() {
  ::reset();
  if (sizeof(children(MOB"cow.c"))<6)
    new(MOB "cow.c")->move(this_object());
  if (!present("fatcow"))
    new(MOB "fatcow.c")->move(this_object());
}
