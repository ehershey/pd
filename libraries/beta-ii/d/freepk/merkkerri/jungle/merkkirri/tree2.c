#include <mjungle.h>
#include <std.h>
inherit VAULT;

void create() {
::create();
set_short("Up in the tree");
set_day_long("You have managed to climb to the top of the tree.  As you peer to the west you see a clearing where a small settlement has been built.  Vast jungle dominates the rest of the nearby landscape.  There appears to be a door built here leading within the tree top.");
set_night_long("You have managed to climb to the top of the tree.  The jungle is pitch black in every direction except to the west where a large bonfire lights up a small settlement.  There appears to be a door built here leading within the tree top.");
set_items(([
"jungle" : "The jungle is dense and lush.  You cant imagine carving out a path through the plants and trees.",
"tree" : "Climbing any higher up would be suicidal.  It's all down from here.",
"door" : "There is a door here that has been built into the side of the tree.  It is approximately seven feet tall and four feet wide.  Strange runes have been carved into the door, perhaps to warn off intruders.",
"settlement": "There is a settlement located in a clearing below and to the west.",
"bonfire": "In the heart of the settlement lies a large bonfire.  You think you see shadows moving near it but from this distance it's hard to be certain.",
"runes": "The runes are unlike any you have ever seen before.  Perhaps they hold some meaning to the Merkkirri people.",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"down": MJUNGLE "tree1.c",
"enter": MJUNGLE "treeroom.c",
]));
set_door("door", MJUNGLE "treeroom.c", "enter", "crystalline key");
set_string("door", "open", "You ignore the runes and open the door.");
}

void reset() {
::reset();
set_open("door", 0);
set_locked("door", 1);
MJUNGLE "treeroom"->set_open("door", 0);
MJUNGLE "treeroom"->set_locked("door", 1);
}
