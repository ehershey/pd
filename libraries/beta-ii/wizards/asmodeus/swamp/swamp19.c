#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Deep within the Merkkirri swamp");
set_day_long("The swamp opens wider here with more area to navigate.  The water is still quite shallow but gets deeper to the south.  Off to the east you see a large body of land but no way to reach it from here.");
set_night_long("The swamp seems to widen here and is still quite shallow.  The water to the south appears deeper but you think you could pass through.");
set_listen("default", "You hear a strange sporadic cry from the island to the east.");
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

"southwest": SWAMP "swamp23.c",
"south": SWAMP "swamp20.c",
"west": SWAMP "swamp24.c",

])); 
}
void reset() {
::reset(); 


ghast = random(100);
if ((ghast) > 93) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 97) { new(MOB "ghast")->move(this_object()); }
 }
}
}
