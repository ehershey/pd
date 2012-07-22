
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
set_short("At the base of a giant tree");
set_long("The massive trees give way to a single tree of enormous size and haunting beauty.  Several small holes sparsely fill the trees trunk where small dwellings have been constructed.");
set_property("swamp",1);
set_items(([
"tree" : "The tree doesn't appear to have any way up other than climbing.",
"dwellings" : "They seem to be the home of some sort of pixies.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([

"southwest": SWAMP "swamp54.c",
"south": SWAMP "swamp55.c",
"northwest": SWAMP "swamp44.c",
"west": SWAMP "swamp53.c",

])); 
}

int treefantastic(string what) {
if (what != "tree") return 0;
if (what == "tree") {
this_player()->move_player(SWAMP "swamp57.c");
return 1;
}
}




void reset() {
::reset();



ghast = random(100);


}
