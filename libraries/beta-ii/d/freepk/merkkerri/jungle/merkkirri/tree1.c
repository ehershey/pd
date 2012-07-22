#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Up in the tree");
set_day_long("You have managed to climb halfway up the tree.  As you peer to the west you see a clearing where a small settlement has been built.  Vast jungle dominates the rest of the nearby landscape.  Looking up towards the top you notice what appears to be door carved into the tree.");
set_night_long("You have managed to climb halfway up the tree.  The jungle is pitch black in every direction except to the west where a large bonfire lights up a small settlement.  Looking up towards the top you notice what appears to be door carved into the tree.");
set_items(([
"jungle" : "The jungle is dense and lush.  You cant imagine carving out a path through the plants and trees.",
"tree" : "You can still climb the tree a ways or you can turn back down.",
"door" : "There is a door near the top of the tree.  Climbing to it shouldn't be much of a problem.",
"settlement": "There is a settlement located in a clearing below and to the west.",
"bonfire": "In the heart of the settlement lies a large bonfire.  You think you see shadows moving near it but from this distance it's hard to be certain.",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"down": MJUNGLE "mjungle6.c",
"climb": MJUNGLE "tree2.c",
]));
add_invis_exit("climb");
}
