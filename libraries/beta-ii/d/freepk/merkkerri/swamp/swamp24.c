#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The thick of the swamp");
set_day_long("The swamp opens up here and continues to the south.  Travel to the west is also possible with a large landmass in that general direction.  With all the dangers you've already encountered, it is no wonder the Merkkirri stay away from this region.");
set_night_long("You are now deep within the swamp and beginning to wonder just how much further you must travel to reach land.  With all the dangers you've already encountered, it is no wonder the Merkkirri stay away from this region.");
set_smell("default", "The air reeks of the slime coating the swamp water.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"water" : "The cool dark swamp water tests your footing.",
"landmass": "The landmass lies far off to the west but you think you can navigate the water to reach it",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"northeast": SWAMP "swamp18.c",
"east": SWAMP "swamp19.c",
"west": SWAMP "swamp25.c",
"southeast": SWAMP "swamp20.c",
"south": SWAMP "swamp23.c",
])); 
}
void reset() {
::reset(); 


ghast = random(100);
if ((ghast) > 97) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 98) { new(MOB "ghast")->move(this_object()); }
 }
}
}
