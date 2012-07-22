#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A dark part of the swamp");
set_day_long("%^BOLD%^GREEN%^The ground here is made up entirely of thick slime and rocks.  It is also the home of one of the swamps worst nightmares...");
set_night_long("%^BOLD%^GREEN%^The ground here is made up entirely of thick slime and rocks.  It is also the home of one of the swamps worst nightmares...");
set_property("swamp",1);
set_items(([

"rocks" : "The rocks are smooth and worn.",
"slime": "Thick green slime coats the entire area.",
]));
set_properties((["light" : 0, "night light" : 0,]));
set_exits(([

"swamp": SWAMP "swamp45.c",


])); 
}
void reset() {
::reset(); 

if(!present("troll")) {
new(MOB "troll")->move(this_object());
}
}
