#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountains" : 1, "town" : 1]) );
  set_short("Platinum Street and Gem Street - Steel Hammer Village");
  set_long(
   "Platinum Street comes to a halt here, leading only west. "
   "There is an intersection here with Platinum and Gem "
   "Streets. Some shops and buildings can be seen along "
   "both of these streets. "
   " Dwarves can be seen hustling around "
   "doing whatever it is that they do. Large mountains "
   "totally surround the village.");
  set_items(([
    "mountains" : "The mountains stretch in all directions. They "
    "surround the small village. ",
    "road" : "A very interesting design. The road is stone, carved "
    "from the mountain, and into various designs. The designs "
    "are very artistic and beautiful.",
    "dwarves" : "Lots of small dwarves are running through "
    "the village.",
    "shops" : "Shops and buildings line both Platinum and "
    "Gem Streets.",
    "buildings" : "Shops and buildings line both Platinum and "
    "Gem Streets."
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "The solf rumble of the village drones the air.");
  set_exits( ([ 
    "west" :  ROOMS "sh_11",
    "south" : ROOMS "s_gem1",
    "north" : ROOMS "n_gem1"]));
}
void reset() {
  ::reset();
  if(!present("sign")) new(ITEMS"sign3.c")->move(this_object());
  if(!present("child")) new(MOB"dwarfgirl1.c")->move(this_object());
  if(!present("child 2")) new(MOB"dwarfgirl1.c")->move(this_object());
}
