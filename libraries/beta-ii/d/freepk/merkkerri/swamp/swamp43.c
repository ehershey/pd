#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Shallow swamp");
set_day_long("The swamp water is very shallow here and the plantlife is quite abundant.  You hear strange animal cries that surely few others have ever heard before.");
set_night_long("The swamp water is very shallow here and the plantlife is quite abundant.  You hear strange animal cries that surely few others have ever heard before.");
set_property("swamp",1);
set_items(([

"water" : "The water is shallow and warm.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"west": SWAMP "swamp42.c",
"northwest" : SWAMP "swamp39.c",
"southwest": SWAMP "swamp45.c",
"east": SWAMP "swamp44.c",

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
