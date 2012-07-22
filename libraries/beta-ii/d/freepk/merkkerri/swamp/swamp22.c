#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The thick of the swamp");
set_day_long("The sweltering sun finds its way through the tree tops here giving you a clear view of your surroundings.  The the south and west the swamp subsides however the water to the west is too deep to cross .");
set_night_long("The sky peeks through the tree tops giving view of the stars.  You hear the sounds of animals scurrying through the swamp to the west but the water there is too deep to cross.");

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

"northeast": SWAMP "swamp20.c",
"north": SWAMP "swamp23.c",
"east": SWAMP "swamp21.c",
//"southeast": SWAMP "swamp102.c",
])); 
}
void reset() {
::reset(); 
if(!present("eel")) {
new(MOB "murkeel")->move(this_object());
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
