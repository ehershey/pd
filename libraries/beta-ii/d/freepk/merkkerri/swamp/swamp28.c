#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A muddy shore");
set_day_long("The ground here is soft and muddy.  Pockets of water fill what look like footprints of various animals and swamp critters.  The swamp begins to the east and thick jungle flora lies to the north.");
set_night_long("The ground here is soft and muddy.  Pockets of water fill what look like footprints of various animals and swamp critters.  The swamp begins to the east and thick jungle flora lies to the north.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"ground" : "The mud is thick and makes movement difficult.",
"footprints": "The footprints assure you that you are far from alone.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"east": SWAMP "swamp27.c",
"northwest": SWAMP "swamp29.c",

])); 
}
void reset() {
::reset(); 

if (!present("dragonfly")) {
new(MOB "irondragonfly")->move(this_object());
new(MOB "irondragonfly")->move(this_object());
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
