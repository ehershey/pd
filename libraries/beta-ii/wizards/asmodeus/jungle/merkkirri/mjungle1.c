#include <mjungle.h>
#include <std.h>
#include <ocean.h>
#include <daemons.h>

inherit BEACH;

void create() {
::create();
set_short("Enterence to the Merkkirri Jungle");
set_day_long("You are on a tiny beach at the outskirts of the Merkkirri Jungle.  A clan of gnolls known as the Merkkirri make thier home here.  The jungle is thick and full of life.  Bugs hover near you waiting for a snack and the humid air clings to you making this a very unpleasant place to be.");
set_night_long("You are on a tiny beach at the outskirts of the Merkkirri Jungle.  A clan of gnolls known as the Merkkirri make thier home here.  The jungle is thick and full of life.  Bugs hover near you waiting for a snack and the humid air, although cooler at night, still clings to you making this a very unpleasant place to be.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"bugs" : "Insects float around you waiting for a moment to take a bite.",
"shadows" : "You think you see shadows stirring within the dark jungle.  You decide it is best to be cautious here.",
]));
set_no_clean(1);
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"north": MJUNGLE "mjungle2.c",
"west": MJUNGLE "mjungle3.c",
]));
set_letter("b");
}
