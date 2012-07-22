#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A small clearing");
set_day_long("This clearing is surrounded by thick trees wrapped in heavy moss.  Several rocks form a slight half circle that encompasses the northern part of the clearing.");
set_night_long("This clearing is surrounded by thick trees wrapped in heavy moss.  Several rocks form a slight half circle that encompasses the northern part of the clearing.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"rocks" : "The rocks form a natural wall to the north and prevent passage.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"southwest": SWAMP "swamp35.c",


])); 
}
void reset() {
::reset(); 

if(!present("bog wraith")) {
new(MOB "bogwraith")->move(this_object());
}

ghast = random(100);
if ((ghast) > 96) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 97) { new(MOB "ghast")->move(this_object()); }
 }
}
}
