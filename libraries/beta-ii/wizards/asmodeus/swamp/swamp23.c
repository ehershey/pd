#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The thick of the swamp");
set_day_long("The water here allows you travel in nearly all directions.  A large land mass lies off to the west and you think it might be possible to work your way in that direction.  The water bugs bite at your legs.");
set_night_long("The water here allows you travel in nearly all directions.  A large land mass lies off to the west and you think it might be possible to work your way in that direction.  The water bugs bite at your legs.");
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
"slime": "The slime is thick and green but appears to be nothing out of the ordinary.",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"northeast": SWAMP "swamp19.c",
"north": SWAMP "swamp24.c",
"east": SWAMP "swamp20.c",
"southwest": SWAMP "swamp21.c",
"northwest": SWAMP "swamp25.c",
"south": SWAMP "swamp22.c",
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
