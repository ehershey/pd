#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;

void create() {
::create();
set_short("The Merkkirri Swamp");
set_day_long("The dark swamp leaves very few options in which to travel.  The eastern waters are very shallow and a traversable path can be made that way.  The still swamp air does nothing to dry the humidity that clings to you.");
set_night_long("The dark swamp leaves very few options in which to travel.  The eastern waters are very shallow and a traversable path can be made that way.  The still swamp air does nothing to dry the humidity that clings to you.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that block the majority of the sunlight.",
"bugs" : "Insects float around you waiting for a moment to take a bite.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to the north and west are quite impressive, these plants are  many times larger and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"east": SWAMP "swamp4.c",
"west":SWAMP "swamp1.c",
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
