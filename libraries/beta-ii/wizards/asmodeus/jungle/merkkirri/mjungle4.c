#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Within the Merkkirri Jungle");
set_day_long("You are in the Merkkirri Jungle.  The jungle is thick and full of life.  The massive trees here support incredible root systems that appear to have once been used by animals as dens.");
set_night_long("You are in the Merkkirri Jungle.  The jungle is thick and full of life.  The massive trees here support incredible root systems that appear to have once been used by animals as dens.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"bugs" : "Insects float around you waiting for a moment to take a bite.",
"shadows" : "You think you see shadows stirring within the dark jungle.  You decide it is best to be cautious here.",
({"leaves", "plants"}): "The plantlife here is drenched from the humidity.",
"trees" : "The trees have enormous roots systems that twist and contort forming pockets beneath.",
"roots" : "The roots of the trees form pockets that animals appear to have used as dens.  One of the pockets appears big enough to enter.",
"pocket" : "The pocket beneath the tree is quite large.  You could easily enter it.",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"south": MJUNGLE "mjungle2.c",
"pocket": MJUNGLE "pocket1.c",
]));
add_invis_exit("pocket");
}
