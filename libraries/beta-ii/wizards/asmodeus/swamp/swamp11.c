#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The lagoon");
set_day_long("The trees have given way to a small lagoon.  The thick green plantlife is showered with sun from above.  You stand within the northwest waters.");
set_night_long("The trees have parted to reveal a star filled sky.  The stale swamp air is slightly more tolerable here.");
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

"northwest": SWAMP "swamp10.c",
"southeast": SWAMP "swamp14.c",
"south": SWAMP "swamp13.c",
"east": SWAMP "swamp12.c",
])); 
}
void reset() {
::reset(); 
if(!present("bog wraith")) {
new(MOB "bogwraith")->move(this_object());
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
