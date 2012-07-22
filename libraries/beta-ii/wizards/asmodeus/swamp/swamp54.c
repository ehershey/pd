#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Shallow swamp");
set_day_long("The massive swamp trees are even larger here as you appear to be in an ancient part of the swamp.  The plants here dwarf the ones you saw only a short distance back.  The sounds of the ocean come from the far east.");
set_night_long("The trees are extremely large here and block out the sky above.  The swamp is filled with the sounds from the creatures of the night.");
set_property("swamp",1);
set_items(([

"trees": "The trees here are enormous as well as the plants nearby.",
"water" : "The water is shallow and warm and a slight current pulls to the east.
 You believe the ocean meets the swamp somewhere in that direction.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"north": SWAMP "swamp53.c",
"east": SWAMP "swamp55.c",
"northeast": SWAMP "swamp56.c",

])); 
}
void reset() {
::reset(); 

if(!present("tangleweed")) {
new(MOB "tangleweed")->move(this_object());
new(MOB "tangleweed")->move(this_object());
}


ghast = random(100);
if ((ghast) > 96) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 98) { new(MOB "ghast")->move(this_object()); }
 }
}
}
