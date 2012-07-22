#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Shallow swamp");
set_day_long("The trees part a ways leaving an open look at the sky above.  The water is stale here but you can hear waves crashing against a shore far to the east.");
set_night_long("The trees part a ways leaving an open look at the sky above.  The water is stale here but you can hear waves crashing against a shore far to the east.");
set_property("swamp",1);
set_items(([

"water" : "The water is shallow and warm and a slight current pulls to the east.
 You believe the ocean meets the swamp somewhere in that direction.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"north": SWAMP "swamp44.c",
"east": SWAMP "swamp56.c",
"south" : SWAMP "swamp54.c",
"southeast": SWAMP "swamp55.c",

])); 
}
void reset() {
::reset(); 


ghast = random(100);
if ((ghast) > 96) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 98) { new(MOB "ghast")->move(this_object()); }
 }
}
}
