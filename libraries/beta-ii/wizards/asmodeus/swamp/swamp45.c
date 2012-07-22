#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A dark part of the swamp");
set_day_long("It is strangely quiet here and quite dark.  Extremely dense plantlife leads to the southwest where the swamp gives way to muddy land.");
set_night_long("It is strangely quiet here and quite dark.  Extremely dense plantlife leads to the southwest where the swamp gives way to muddy land.");
set_property("swamp",1);
set_items(([

"water" : "The water is shallow and warm and a slight current pulls to the east.  You believe the ocean meets the swamp somewhere in that direction.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"north": SWAMP "swamp42.c",
"northeast" : SWAMP "swamp43.c",
"southwest": SWAMP "swamp47.c",

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
