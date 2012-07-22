#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountains" : 1, "town" : 1]) );
  set_short("Platinum Street and Gem Street - Steel Hammer Village");
  set_long(
   "Copper street leads east and west. A tall tower has been "
   "carved from stone here. A withered old tree stands "
   "next to the tower. High mountain walls prevent access "
   "south of here. Another mountain wall isn't far off "
   "to the east and homes are off to the west.");
  set_items(([
    "mountains" : "The mountains stretch in all directions. They "
    "surround the small village. ",
    "road" : "A very interesting design. The road is stone, carved "
    "from the mountain, and into various designs. The designs "
    "are very artistic and beautiful.",
    "tree" : "An old withered tree stands next to the tower. "
    "Local lore has it that the tree, which once grew "
    "stronger than any other around, has slowly been "
    "killed off because of radiation from the magical "
    "experiments from within the tower..",
    "window" : "A lone window atop the tower can be seen with "
    "an almost blinding %^BOLD%^%^CYAN%^light blue%^RESET%^ "
    "light shining through.",
    "homes" : "Several homes can be seen along Copper Street."
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "The soft rumble of the village drones the air.");
  set_exits( ([ 
    "west" :  ROOMS "e_copper3.c",
    "south" : ROOMS "towerent.c",
    "east" : ROOMS "s_gem3"]));
}
void reset() {
  ::reset();
  if(!present("villager")) new(MOB"villager2.c")->move(this_object());
}
