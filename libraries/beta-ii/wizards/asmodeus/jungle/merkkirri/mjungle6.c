#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Near a giant tree");
set_day_long("You find yourself at the base of a giant tree.  The jungle surrounding the tree becomes thick an unpassable except for the path that led you here.  You find it odd that the path here is so worn.  It is almost as if someone must come here often.");
set_night_long("You find yourself at the base of a giant tree.  The jungle surrounding the tree becomes thick an unpassable except for the path that led you here.  You find it odd that the path here is so worn.  It is almost as if someone must come here often.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  You cant imagine carving out a path through the plants and trees.",
"tree" : "The tree is quite enormous.  The shape of the bark would allow for easy climbing.",
"path" : "The path here looks well used and leads to the base of the tree.",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"south": MJUNGLE "mjungle5.c",
"climb": MJUNGLE "tree1.c",
]));
add_invis_exit("climb");
}
