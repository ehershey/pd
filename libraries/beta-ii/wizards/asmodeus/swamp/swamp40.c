#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A trail within the swamp");
set_day_long("Stepping out of the water you walk upon a muddy shore bordering the jungles to the north  A faint trail can again be seen here leading to the north.");
set_night_long("Stepping out of the water you walk upon a muddy shore that borders the merkkirri jungle to the north.  In the faint light you notice many broken branches in the area that seem to indicate something has been through here.");
set_property("swamp",1);
set_smell("default", "The smell of decaying flesh seems to loft in from the north.");
set_items(([
"mud" : "The mud is sorta like dirt and water.",
"water" : "The water is dank and warm as it is rather shallow.",
"branches": "It appears something or someone has been through here recently.",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([

"southwest": SWAMP "swamp39.c",
"north" : SWAMP "swamp41.c",

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
