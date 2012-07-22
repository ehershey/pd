#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Within the shallow swamp");
set_day_long("Sunlight breaks through the thick vegitation above, forming bright sunbeams shooting down to the water.  The humid air nearly chokes you.");
set_night_long("You stumble along a shallow path within the swamp.  The cries of nocturnal animals are the only sounds that break the haunting silence.");
set_property("swamp",1);
set_smell("default", "Putrid airs loft from the slime covering the water.");
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"sunbeams" : "Wooooooo..... nifty.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"northeast": SWAMP "swamp5.c",
"east":SWAMP "swamp8.c",
])); 
}
void reset() {
::reset(); 
if(!present("alligator")) {
new(MOB "alligator")->move(this_object());
}
ghast = random(100);
if ((ghast) > 97) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 98) { new(MOB "ghast")->move(this_object()); }
 }
}
}
