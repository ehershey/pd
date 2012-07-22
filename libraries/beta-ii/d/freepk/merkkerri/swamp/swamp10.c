#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Into the lagoon");
set_day_long("You find yourself getting deeper and deeper into the swamp water.  The murky path you have followed begins to open into a small lagoon to the southeast.  Off to the northwest you can see the region you came from.");
set_night_long("The water begins to get deeper and deeper.  The trees part way to a small lagoon to the southeast.");
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

"northwest": SWAMP "swamp8.c",
"southeast": SWAMP "swamp11.c",
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
