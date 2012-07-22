#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("North end of a clearing");
set_day_long("The trees part and give way to a sun filled sky.  This appears to be the northern edge of a clearing within the swamp.  Shallow water engulfs the entire region and you marvel at the millions of insects basking in the suns rays.");
set_night_long("The trees part and give way to a star filled sky.  This appears to be the northern edge of a clearing within the swamp.  Shallow water engulfs the entire region.");
set_property("swamp",1);
set_listen("default", "The buzzing of millions of insects is quite loud.");
set_items(([
"trees" : "The trees are large and broad at the base.",
"water" : "The water is dank and warm as it is rather shallow.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 2, "night light" : 1,]));
set_exits(([

"southeast": SWAMP "swamp43.c",
"northwest" : SWAMP "swamp38.c",
"south" : SWAMP "swamp42.c",
"northeast" : SWAMP "swamp40.c",

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
