#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The path suddenly veers west and recklessly crashes into a large structure. The structure is a large mill, with a large fan on top and a wheel in the water. The path also goes south. There is a river flowing southwest to the west of your current location. The door to the building is wide open. A wide house can be seen to the northwest across the river.");
  set_night_long("The path turns west into a large structure. The structure is a large, black mill, with a large fan on top that turns eerily in the wind, and a wheel in the water. The path also goes south. There is a river flowing southwest to the west of your current location. The door to the building is wide open. A wide house can be seen to the northwest across the river.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes southwest, and then turns north and terminates at a house's door steps.",
    "fan" : "It is on top of the windmill. It turns whenever there is wind.",
    "wheel" : "The wheel turns slowly, along with the rivers current.",
    "river" : "It is to the east of here, the path is following it. The river curves west around to the west.",
    "house" : "The farmer's house."
   ]));
  set_listen("default", "The sound of the rotating wheel of the waterwheel fills the air.");
  set_exits(([
    "enter" : ROOMS"farm37",
    "south" : ROOMS"farm25"
   ]));
}
void reset() {
  ::reset();
  if (!present("mill"))
    new(OBJ"mill.c")->move(this_object());
}
