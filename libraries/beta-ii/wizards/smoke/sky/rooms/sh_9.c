#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountains" : 1, "town" : 1]) );
  set_short("Platinum Street and Gold Street- Steel Hammer Village");
  set_long(
   "There is an intersection here between Platinum Street "
   "and Gold Street. There are buildings along both roads. "
   "The roads have very beautiful designs carved into them. "
   "Dwarven villagers are all over the village, doing whatever "
   "it is that they do. Giant mountains surround the small "
   "village. A large monastery is ahead to the east. ");
  set_items(([
    "mountains" : "The mountains stretch in all directions. They "
    "surround the small village. ",
    "platinum street" : "Platinum Street is the main street in the "
    "village. It runs east and west and is usually very busy.",
    "houses" : "Small stone buildings that have been carved from the "
    "mountains lie ahead. They're all in different "
    "shapes and sizes, but they are all pretty small.",
    "gold street" : "Gold Street is a residential street. There "
    "are many houses on the east side of the street and the"
    " mountains act as the city wall on the western side.",
    "roads" : "A very interesting design. The road is stone, carved "
    "from the mountain, and into various designs. The designs "
    "are very artistic and beautiful.",
    "monastery" : "A huge monastery is ahead to the east. It "
    "looks as though it takes up the entire block.",
    "dwarves" : "Dwarves are seen through the gate running all "
    "around the village, taking part in their daily activities."
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "The solf rumble of the village drones the air.");
  set_exits( ([ 
    "west" :  ROOMS "sh_8",
    "north" : ROOMS "n_gold1",
    "south" : ROOMS "s_gold1",
    "east" :  ROOMS "sh_10"]));
}
void reset() {
  ::reset();
  if(!present("sign")) new(ITEMS"sign2.c")->move(this_object());
  if(!present("child")) new(MOB"dwarfgirl1.c")->move(this_object());
  if(!present("villager 2")) new(MOB"villager1.c")->move(this_object());
}
