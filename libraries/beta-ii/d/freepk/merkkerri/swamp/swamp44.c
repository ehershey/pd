#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Shallow swamp");
set_day_long("The swamp water is very shallow here and the plantlife is quite abundant.  The swamp opens up largely to the south and far to the east the sounds of waves crashing along a shore can be heard.  There seems to be a very faint current heading in that direction.");
set_night_long("The swamp water is very shallow here and the plantlife is quite abundant.  The swamp opens up largely to the south and far to the east the sounds of waves crashing along a shore can be heard.  There seems to be a very faint current heading in that direction.");
set_property("swamp",1);
set_items(([

"water" : "The water is shallow and warm and a slight current pulls to the east.  You believe the ocean meets the swamp somewhere in that direction.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"west": SWAMP "swamp43.c",
"south" : SWAMP "swamp53.c",
"southeast": SWAMP "swamp56.c",

])); 
}
void reset() {
::reset(); 

if(!present("swamp devil")) {
new(MOB "swampdevil.c")->move(this_object());
new(MOB "swampdevil.c")->move(this_object());
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
