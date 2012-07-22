
#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;

void init() {
::init();
add_action("treefantastic", "climb");

}

void create() {
::create();
set_short("A small courtyard");
set_long("Here several giant branches come together forming a platform that has been converted into a small courtyard.  The pixie king usually sits here upon a throne made of vines.");
set_property("swamp",1);
set_items(([
"tree" : "The tree doesn't appear to have any back down except climbing.",
"dwellings" : "They seem to be the home of some sort of pixies.",
"walkway": "The walkway looks as ancient as the tree itself.",
"region": "The ocean borders the great island to the east as the swamp flows into its endless boundries.",
"throne": "The throne is made entirely of thick swamp vines.",

]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([

"south": SWAMP "swamp61.c",
"north": SWAMP "swamp58.c",
"east": SWAMP "swamp60.c",
"west": SWAMP "swamp57.c",
])); 
new(SWAMP "leafthrone")->move(this_object());
}

int treefantastic(string what) {
if (what != "tree") return 0;
if (what == "tree") {
this_player()->move_player(SWAMP "swamp56.c");
return 1;
}
}




void reset() {
::reset();

if(!present("pixie")) {
new(MOB "treepixie")->move(this_object());
new(MOB "treepixie")->move(this_object());
}
if(!present("pixie king")) {
new(MOB "pixieking.c")->move(this_object());
}

ghast = random(100);


}
