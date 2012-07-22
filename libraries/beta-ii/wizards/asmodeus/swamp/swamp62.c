#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Shallow swamp");
set_day_long("The swamp winds through countless trees and other obsticles while opening up in nearly all directions.  Thousands of misquitoes hover along the shallow water as they lay eggs or search for food.");
set_night_long("The swamp winds through countless trees and other obsticles while opening up in nearly all directions.  The trees obscure nearly all the light in this area.");
set_property("swamp",1);
set_listen("default", "The howls of strange beasts can be heard off in the distance.");
set_items(([

"trees": "The trees dominate the landscape.",
"water" : "The water is shallow and warm and a slight current pulls to the east.
 You believe the ocean meets the swamp somewhere in that direction.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"north": SWAMP "swamp55.c",
"east": SWAMP "swamp63.c",
"southwest": SWAMP "swamp65.c",
"south" : SWAMP "swamp64.c",

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
