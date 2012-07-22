#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The path gently glides west and makes an instant right angle turn to head north back towards the river that is to the west of here. To the north there is a mill half inside and half outside of the river.");
  set_night_long("The shadow covered path crawls west and makes an instant right angle turn, as if afraid of something lurking in the dark, to head north back towards the river. To the north there is a mill half inside and half outside of the river.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes southwest, and then turns east.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the northeast.",
    "waterwheel" : "It is a watermill/windmill crossbreed. It is to the northeast.",
    "river" : "It is to the west of here, the path turns away from it.",
    "house" : "The farmer's house."
   ]));
  set_smell("default", "It smells like freshly cut grass here.");
  set_listen("default", "The gentle rushing of the river can be heard.");
  set_exits(([
    "west" : ROOMS"farm24",
    "north" : ROOMS"farm26"
   ]));
}
void reset() {
  ::reset();
  if (sizeof(children(MOB"wandchicken.c"))==0)
    new(MOB "wandchicken.c")->move(this_object());
}
