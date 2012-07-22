#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
 set_long("The path goes diagonally northeast and southwest. The path follows a river to the east. To the southeast there is a mill, but it is across the river. To the northeast the path suddenly curves north and then instantly runs into the door of a very wide house.");
 set_night_long("The path goes diagonally northeast and southwest. The path follows a river to the east, as if afraid to go by itself into the darkness. To the southeast there is a mill, but it is across the dark river. To the northeast the path suddenly curves north and then instantly runs into the door of a very wide house. There is light flooding out from all the windows of the house, making it very welcoming.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes south and north.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the east, across the river.",
     "mill" : "It is a watermill/windmill crossbreed. It is to the east, across the river.",
   "waterwheel" : "It is a watermill/windmill crossbreed. It is to the east, across the river.",
    "river" : "It is to the east of here, the path is following it.",
    "house" : "The farmer's house."
   ]));
  set_smell("default", "It smells like freshly cut grass here.");
  set_listen("default", "The gentle rushing of the river can be heard.");
  set_exits(([
    "northeast" : ROOMS"farm21",
    "southwest" : ROOMS"farm19"
   ]));
}
void reset() {
  ::reset();
  if (!present("horse"))
    new(MOB"horse.c")->move(this_object());
}
