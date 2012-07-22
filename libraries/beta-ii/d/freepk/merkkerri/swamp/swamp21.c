#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The thick of the swamp");
set_day_long("The swamp continues in all directions but the water to the east is far too deep to traverse safely.  The giant swamp trees begin to cluster tightly to the south and it appears that land can be reached in that direction eventually .");
set_night_long("The cold swamp water is difficult to travel through but you find you can manage in most directions.");
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

"north": SWAMP "swamp20.c",
"west": SWAMP "swamp22.c",
"northwest": SWAMP "swamp23.c",
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
