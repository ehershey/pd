#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Shallow swamp");
set_day_long("The ground here is completely submerged beneath shallow swamp water.  Long leafy plants and cat tails grow throughout the area.");
set_night_long("The ground here is completely submerged beneath shallow swamp water.  Dark shadows surround you but in this faint light it is difficult to distinguish what you are looking at without excellent night vision.");
set_property("swamp",1);
set_items(([
"shadows" : "They could be plants, people, or even space monkeys from Xarcon IV.",
"water" : "The faint trail disappears into the water.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"north": SWAMP "swamp39.c",
"east" : SWAMP "swamp43.c",
"south": SWAMP "swamp45.c",

])); 
}
void reset() {
::reset(); 

if(!present("bog wraith")) {
new(MOB "bogwraith")->move(this_object());
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
