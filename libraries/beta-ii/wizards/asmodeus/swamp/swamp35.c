#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A trail along the swamp");
set_day_long("The trail extends to the east and west and you notice a small clearing to the northeast.  The massive leaves keep the sun off of you which is a welcome relief in the sweltering heat.");
set_night_long("The trail seems to go to the east and west.  A clearing lies to the northeast.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"water" : "The swamp is just to the south of you.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"northeast": SWAMP "swamp36.c",
"east": SWAMP "swamp37.c",
"west" : SWAMP "swamp9.c",

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
