#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountains" : 1, "town" : 1]) );
  set_short("A mage tower");
  set_long(
   "A mage tower stands tall here. Steps lead down back to "
   "Copper Street and an open doorway leads inside. "
   "The tower is carved from the stone of the "
   "mountain. Two gargoyles carved into the tower seem "
   "to watch over things.");
  set_items(([
    "tower" : "The tall mage tower stands before you.",
    "doorway" : "An open doorway carved into the tower leads "
    "inside.",
    "gargoyles" : "The gargoyles idly sit by. ",
    "steps" : "A few stone steps lead back down to Copper Street. "
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "The solf rumble of the village drones the air.");
  set_exits( ([ 
    "enter tower" :  ROOMS "tower1_1",
    "north" :  ROOMS "e_copper4"]));
}
void reset() {
  ::reset();
  if(!present("gargoyle")) new(ITEMS"gargoyle.c")->move(this_object());
  if(!present("gargoyle 2")) new(ITEMS"gargoyle.c")->move(this_object());
  if(!present("tower")) new(ITEMS"tower.c")->move(this_object());

}
