#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountains" : 1, "town" : 1]) );
  set_short("Platinum Street - Steel Hammer Village");
  set_long(
   "Platinum Street runs east and west. A small, stone house  "
   "stands on the north side of the road. An intersection is "
   "just west of here. It gets busier farther east. Dwarves "
   "are all over town. The mountains totally encompass the "
   "small village. More houses and buildings are all over "
   "the village. ");
  set_items(([
    "mountains" : "The mountains stretch in all directions. They "
    "surround the small village. ",
    "platinum street" : "Platinum Street is the main street in the "
    "village. It runs east and west and is usually very busy.",
    "houses" : "Small stone buildings that have been carved from the "
    "mountains lie ahead. They're all in different "
    "shapes and sizes, but they are all pretty small.",
    "road" : "A very interesting design. The road is stone, carved "
    "from the mountain, and into various designs. The designs "
    "are very artistic and beautiful.",
    "house" : "There is a small, stone house built on the northern "
    "side of Platinum Street. It is the same gray color as the "
    "mountains. A wooden door is partially open.",
    "dwarves" : "Dwarves are seen through the gate running all "
    "around the village, taking part in their daily activities.",
    "buildings" : "Many small buildings can be seen through the "
    "village."
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "The solf rumble of the village drones the air.");
  set_exits( ([ 
    "west" :  ROOMS "sh_3",
    "enter house" : ROOMS "house1",
    "east" :  ROOMS "sh_5"]));
}
void reset() {
  ::reset();
  if(!present("child")) new(MOB"dwarfboy1.c")->move(this_object());
  if(!present("child 2")) new(MOB"dwarfgirl1.c")->move(this_object());
}
