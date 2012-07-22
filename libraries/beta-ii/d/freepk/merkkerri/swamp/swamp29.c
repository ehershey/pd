#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A large island");
set_day_long("You stand upon a large island located on the far west side of the swamp.  The giant trees engulf the sky making it dark even during the brightest day.  The air here is stale yet cold when compared to the rest of the swamp.");
set_night_long("You stand upon a large island located on the far west side of the swamp.  The giant trees engulf the sky, keeping the ground free from any moonlight.  The air here is stale yet cold when compared to the rest of the swamp.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"island": "You stand upon a large island.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 0, "night light" : 0,]));
set_exits(([

"northeast": SWAMP "swamp30.c",
"north": SWAMP "swamp31.c",
"southeast" : SWAMP "swamp28.c",

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
