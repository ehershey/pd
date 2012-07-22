#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The thick of the swamp");
set_day_long("This part of the jungle is submerged in shallow water and travel in all but a few directions is impossible.  Giant trees, possibly untouched for eons, inhabit the murky waters.  Land lies directly to the west.");
set_night_long("This part of the jungle is submerged in shallow water and travel in all but a few directions is impossible.  Giant trees, possible untouched for eons, inhabit the murky waters.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"water" : "The cool dark swamp water tests your footing.",
"land": "The landmass lies off to the west and you think you can navigate
the water to reach it",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"west": SWAMP "swamp28.c",
"north": SWAMP "swamp26.c",

])); 
}
void reset() {
::reset(); 


ghast = random(100);
if ((ghast) > 95) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 97) { new(MOB "ghast")->move(this_object()); }
 }
}
}
