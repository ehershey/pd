#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;

void create() {
::create();
set_short("The Merkkirri Swamp");
set_day_long("The dark swamp leaves very few options in which to travel.  The southern waters however, seem shallow enough to traverse.  Large dragonflies and mosquitoes buzz around your face while strange calls of birds and animals echo through the area.");
set_night_long("The dark swamp leaves very few options in which to travel.  The southern waters however, seem shallow enough to traverse.  Large dragonflies and mosquitoes buzz around your face while strange calls of birds and animals echo through the area.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that block the majority of the sunlight.",
"bugs" : "Insects float around you waiting for a moment to take a bite.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to the north and west are quite impressive, these plants are  many times larger and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"north": SWAMP "swamp1.c",
"southeast":SWAMP "swamp5.c",
]));
}
void reset() {
::reset(); 
if(!present("boar")) {
new(MOB "blackboar")->move(this_object());
}
ghast = random(100);
if ((ghast) > 93) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 97) { new(MOB "ghast")->move(this_object()); }
 }
}
}


