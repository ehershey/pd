#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The lagoon");
set_day_long("You stand in the southeastern portion of the lagoon.  The thick tree bases begin to close off much of the south and east directions but travel through is still possible.");
set_night_long("You stand in the southeastern portion of the lagoon.  The thick tree bases begin to close off much of the south and east directions but travel through is still possible.");
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

"southeast": SWAMP "swamp18.c",
"north": SWAMP "swamp14.c",
"northwest": SWAMP "swamp13.c",
"west": SWAMP "swamp15.c",
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
