#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1]) );
  set_short("%^ORANGE%^A barn.%^RESET%^");
  set_long("The huge doors to the barn are so heavy that they are unmovable. The grass waves gently in the wind to the south. Although the barn looks fairly new the wind howls outside. The barn extends even more to the west. It is nice and cozy in here, and it looks fairly cold outside.");
  set_items(([
    "door" : "The door is huge and impossible to close.",
    "doors" : "They are huge and impossible to close.",
    "barn" : "You are inside it.",
   ]));
  set_listen("default", "The grass rustles gently in the wind.");
  set_exits(([
    "west" : ROOMS"farm32",
    "south" : ROOMS"farm11"
   ]));
}
