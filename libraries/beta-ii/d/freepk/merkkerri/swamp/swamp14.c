#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The lagoon");
set_day_long("You stand near the middle of the lagoon and the water proves to be rather shallow here.   Several water bugs glide along the cool swamp.");
set_night_long("You stand near the middle of the lagoon.  Thousands of stars glisten in the dark sky.  You notice the air is cooler here.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"lagoon": "The lagoon is rather small but could be deep.",
"water" : "The cool dark swamp water tests your footing.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"northwest": SWAMP "swamp11.c",
"north": SWAMP "swamp12.c",
"south": SWAMP "swamp17.c",
"southwest": SWAMP "swamp15.c",
"west": SWAMP "swamp13.c",
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
