#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
    "no teleport" : 1]) );
  set_short("a house");
  set_long(
   "This house has been carved from the stone of the mountain."
   " Windows and a partially open door on the south wall "
   "lead to Platinum Street. The bare stone floor is "
   "cold to the touch. A fireplace on the north wall "
   "is lit with a burning fire that's heating a cauldron.");
  set_items(([
    "windows" : "Windows show Platinum Street running "
    "east and west.",
    "walls" : "The stone walls have been carved from "
    "the mountain itself.",
    "door" : "The door is cracked and leads south to "
    "Platinum Street.",
    "fire" : "The fire crackles in the fireplace. A small "
    "cauldron is being warmed over the fire.",
    "fireplace" : "The stone fireplace currently contains "
    "a busy fire which is heating a small cauldron.",
    "cauldron" : "The small black cauldron is holding what "
    "smells bison stew. It is being heated over the fire."
   ]));
  set_smell("default", "It smells like some good home cooking.");
  set_exits( ([ 
    "out" :  ROOMS "sh_4"]));
}
void reset() {
  ::reset();
  if(!present("villager")) new(MOB"villager2.c")->move(this_object());
}
