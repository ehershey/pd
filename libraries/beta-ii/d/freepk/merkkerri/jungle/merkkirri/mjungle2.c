#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Within the Merkkirri Jungle");
set_day_long("You are in the Merkkirri Jungle.  The jungle is thick and full of life.  Bugs hover near you waiting for a snack and the humid air clings to you making this a very unpleasant place to be.  Sounds of dripping water can be heard as the leaves of the plants and trees are soaked in moisture.");
set_night_long("You are in the Merkkirri Jungle.  The jungle is thick and full of life.  Bugs hover near you waiting for a snack and the humid air clings to you making this a very unpleasant place to be.  Sounds of dripping water can be heard as the leaves of the plants and trees are soaked in moisture.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"bugs" : "Insects float around you waiting for a moment to take a bite.",
"shadows" : "You think you see shadows stirring within the dark jungle.  You decide it is best to be cautious here.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"north": MJUNGLE "mjungle4.c",
"south": MJUNGLE "mjungle1.c",
"northwest": MJUNGLE "mjungle5.c",
]));
}
