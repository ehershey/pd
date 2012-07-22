#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The thick of the swamp");
set_day_long("The swamp has widened here considerably and the water is rather deep.  The east remains unpassable but you can manage your way in most other directions.");
set_night_long("The swamp has widened here considerably and the water is rather deep.  The east remains unpassable but you can manage your way in most other directions.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"water" : "The cool dark swamp water tests your footing.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"south": SWAMP "swamp21.c",
"north": SWAMP "swamp19.c",
"west": SWAMP "swamp23.c",
"southwest": SWAMP "swamp22.c",
"northwest": SWAMP "swamp24.c",
])); 
}
void reset() {
::reset(); 
if(!present("dragonfly")) {
new(MOB "irondragonfly")->move(this_object());
new(MOB "irondragonfly")->move(this_object());
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
