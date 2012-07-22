#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1]) );
  set_short("%^ORANGE%^A barn.%^RESET%^");
  set_long("It is nice and warm up in this hayloft. The wind can be heard tearing at the outside of the barn, but for now the haylofy stays nice and warm. There are many piles of hay and straw up here, perfect for young children to hide in. The stairs to the south lead down and out of the hayloft.");
  set_items(([
    "hayloft" : "There are many piles of hay in the hayloft.",
    "stairs" : "The stairs lead south and down into the rest of the barn.",
    "hay" : "There are piles of hay all over the place.",
    "straw" : "There are piles of straw all over the place.",
    "barn" : "You are inside it.",
   ]));
  set_listen("default", "The wind whips into the barn and makes loud howling noises.");
  set_smell("default", "The fridgid temperatures freeze your nose.");
  set_exits(([
    "south" : ROOMS"farm32"
   ]));
}
void reset() {
  if (!present("hay")) new(OBJ"hay.c")->move(this_object());
  if (!present("youngman")) new(MOB"youngman.c")->move(this_object());
  if (!present("youngwoman")) new(MOB"woman.c")->move(this_object());
}
