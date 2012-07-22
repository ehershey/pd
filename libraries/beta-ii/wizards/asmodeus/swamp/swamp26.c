#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The thick of the swamp");
set_day_long("From here the swamp opens to the east while land begins to
show itself to the west.  The mighty trees begin to engulf you.");
set_night_long("You can barely make out land visible to the west and like the
rest of the swamp, finding a way to it may prove a challenge.  The swamp opens
up to the east while the massive jungle trees engulf the other directions.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"water" : "The cool dark swamp water tests your footing.",
"land": "The landmass lies far off to the west but you think you can navigate
the water to reach it",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"south": SWAMP "swamp27.c",
"northeast": SWAMP "swamp25.c",

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
