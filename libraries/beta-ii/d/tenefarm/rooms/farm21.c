#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The path follows a river to the southwest, right next to the river. The path suddenly curves north here and goes into the farmer's house. The river curves around behind the house and continues west, but it flows in the opposite direction. To the southeast a mill can be seen across the river.");
  set_night_long("The path follows a river to the southwest, right next to the river. The path suddenly curves north here and goes into the farmer's house. The river curves around behind the house and continues west, but it flows in the opposite direction. To the southeast a mill can be seen across the river. All of the lights are on in the house, making it look very inviting.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes southwest, and then turns north and terminates at a house's door steps.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the east, across the river.",
    "waterwheel" : "It is a watermill/windmill crossbreed. It is to the east, across the river",
    "river" : "It is to the east of here, the path is following it. The river curves west around to the west.",
    "house" : "The farmer's house."
   ]));
  set_smell("default", "It smells like freshly cut grass here.");
  set_listen("default", "The gentle rushing of the river can be heard.");
  set_exits(([
    "southwest" : ROOMS"farm20"
   ]));
}
void reset() {
  ::reset();
  if (!present("house"))
    new(OBJ"house.c")->move(this_object());
}
