#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A large island");
set_day_long("The northern part of the island is surrounded by thick trees and plantlife.  There is a small wedge between two of the trees leading to a small clearing northwest.  The air is quite cold here.");
set_night_long("The northern part of the island is surrounded by thick trees and plantlife.  There is a small wedge between two of the trees leading to a small clearing northwest.  The air is quite cold here.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.  You can squeeze to the northwest through a wedge between two of the trees.",
"island": "You stand upon a large island.",
"plantlife": "The plantlife has completely overgrown this portion of the island.",
]));
set_properties((["light" : 0, "night light" : 0,]));
set_exits(([

"southwest": SWAMP "swamp31.c",
"northwest": SWAMP "swamp33.c",
"south" : SWAMP "swamp30.c",

])); 
}
void reset() {
::reset(); 


ghast = random(100);
if ((ghast) > 94) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 96) { new(MOB "ghast")->move(this_object()); }
 }
}
}
