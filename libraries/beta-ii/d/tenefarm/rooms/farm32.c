#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1]) );
  set_short("%^ORANGE%^A barn.%^RESET%^");
  set_long("The barn extends to the east. To the north stairs lead up into the hayloft. There is a single stable here, but the door seems to have been blown off. The door to the stable lays on the floor. There must be a draft in this barn, because the wind blows through and chills your body to the bone.");
  set_items(([
       "stable" : "the door to the stable appears to have been kicked off.",
    "door" : "The door to the stable lies on the floor. Looks like someone did some pretty shoddy woodwork.",
    "hayloft" : "There are many piles of hay in the hayloft.",
    "stairs" : "The stairs lead north and up into the hayloft.",
    "barn" : "You are inside it.",
   ]));
  set_listen("default", "The wind whips into the barn and makes loud howling noises.");
  set_smell("default", "The fridgid temperatures freeze your nose.");
  set_exits(([
    "east" : ROOMS"farm31",
    "north" : ROOMS"farm33"
   ]));
}
