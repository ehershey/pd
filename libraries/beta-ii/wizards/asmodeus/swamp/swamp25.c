#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The thick of the swamp");
set_day_long("From here the swamp opens to the southeast while land begins to show itself to the west.  The shallow water here makes it easier to travel for you or for those who might be stalking you...");
set_night_long("You can barely make out land visible to the west and like the rest of the swamp, finding a way to it may prove a challenge.  The swamp opens up from here to the southeast where the waters are colder and deeper.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"water" : "The cool dark swamp water tests your footing.",
"land": "The landmass lies far off to the west but you think you can navigate the water to reach it",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"southeast": SWAMP "swamp23.c",
"east": SWAMP "swamp24.c",
"southwest": SWAMP "swamp26.c",

])); 
}
void reset() {
::reset(); 
if(!present("swamp devil")) {
new(MOB "swampdevil")->move(this_object());
new(MOB "swampdevil")->move(this_object());
}

ghast = random(100);
if ((ghast) > 95) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 97) { new(MOB "ghast")->move(this_object()); }
 }
}
}
