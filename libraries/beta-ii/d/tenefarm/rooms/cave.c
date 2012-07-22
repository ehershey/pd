#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 1 ]) );
  set_short("%^BOLD%^%^BLACK%^A cave%^RESET%^");
  set_long("The barren walls of this cave are made of cobbled rocks and pebbles that vary in shape and size. There is a small hole in the ceiling where only a small trickle of water flows through, splashing gently against the ground and collecting in a small yet consistant stream of water that flows through the room. The room is damp yet dry, except for the stream of water crawling through the room.");
  set_items(([
    "ceiling" : "It has a hole in it.",
    "trickle" : "It falls through the hole in the ceiling and forms a small stream on the floor.",
    "stream" : "It originates on the floor in the center of the room and flows out inbetween the rocks that make up the wall.",
    ({ "wall", "walls" }) : "It is made up of various rocks and pebbles that appear to have been cobbled together. The wall doesn't seem very sturdy, but it must be, otherwise it would not be able to keep the water pressure from the river above from collapsing it.",
    ({ "rocks", "pebbles" }) : "They make up the walls to this cave. They are of various shapes and sizes, but most of them are grey, with the light green one thrown in here and there.",
    ({ "rock", "pebble" }) : "It, along with its brother and sister rocks, make up the walls of the cave.",
    "hole" : "The hole is too far away to closely examine, so you position yourself directly underneath it to, in order to get a better view.\nYou can see the water from the river above flowing by with tremendous force. It's astounding that only a trickle of water flows through the hole, rather than the river crashing down through the hole and reclaiming the cave as its own.",
    ({ "water", "river" }) : "Upon closer inspection, it seems that, as the water flows by the hole in the ceiling, it begins to enter the cave and is then reflected out back into the river above by some powerful magic.",
   ]));
  set_exits(([
    "up" : ROOMS"farm22",
   ]));
}
void reset() {
  ::reset();
  if (!present("wnymph"))
    new(MOB "wnymph.c")->move(this_object());
}
