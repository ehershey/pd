#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A trail along the swamp");
set_day_long("The trail continues to the northwest but to the southeast it quickly becomes submerged beneath the shallow swamp waters.  The water looks shallow enough to navigate.");
set_night_long("The trail continues to the northwest but to the southeast it quickly becomes submerged beneath the shallow swamp waters.  The water looks shallow enough to navigate.");
set_property("swamp",1);
set_items(([
"trail" : "The trail is faint and appears to have very infrequent use.  It might just be the path left by a large predator.",
"water" : "The faint trail disappears into the water.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"southeast": SWAMP "swamp39.c",
"northwest" : SWAMP "swamp37.c",

])); 
}
void reset() {
::reset(); 

if(!present("eel")) {
new(MOB "murkeel")->move(this_object());
new(MOB "murkeel")->move(this_object());
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
