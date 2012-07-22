#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A dark part of the swamp");
set_day_long("The water here is shallow and warm.  Everything looks the same...");
set_night_long("The water here is shallow and warm.  Everything looks the same...");
set_property("swamp",1);
set_items(([

"water" : "The water is shallow and warm.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 0, "night light" : 0,]));
set_exits(([

"north": SWAMP "swamp47.c",
"east": SWAMP "swamp47.c",
"south": SWAMP "swamp47.c",
"west": SWAMP "swamp51.c",
"northeast" : SWAMP "swamp47.c",
"southwest": SWAMP "swamp47.c",
"northwest": SWAMP "swamp47.c",
"southeast": SWAMP "swamp47.c",

])); 
}
void reset() {
::reset(); 


ghast = random(100);
if ((ghast) > 94) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 97) { new(MOB "ghast")->move(this_object()); }
 }
}
}
