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
set_short("The upper walkway");
set_long("From here the entire region can be seen as you stand upon a large
wooden walkway that surrounds the upper tree.  Pixies can be seen flying to and
fro while occassionally landing upon the walkway for a closer look at their
visitors.");
set_property("swamp",1);
set_items(([
"tree" : "The tree doesn't appear to have any back down except climbing.",
"dwellings" : "They seem to be the home of some sort of pixies.",
"walkway": "The walkway looks as ancient as the tree itself.",
"region": "The ocean borders the great island to the east as the swamp flows
into its endless boundries.",

]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([

"northwest": SWAMP "swamp58.c",
"southwest": SWAMP "swamp61.c",
"west": SWAMP "swamp59.c",

])); 
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

ghast = random(100);


}
