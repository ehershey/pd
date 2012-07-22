#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Within the shallow swamp");
set_day_long("You walk along the swamp often zig-zagging to find places shallow enough to travel.  You feel tiny insects relentlessly biting you from beneath the water.");
set_night_long("You walk along the swamp often zig-zagging to find places shallow enough to travel.  You feel tiny insects relentlessly biting you from beneath the water.");
set_property("swamp",1);
set_smell("default", "Putrid airs loft from the slime covering the water.");
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"insects" : "While you cant see the insects you sure can feel them.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"northwest": SWAMP "swamp2.c",
"southwest":SWAMP "swamp6.c",
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
