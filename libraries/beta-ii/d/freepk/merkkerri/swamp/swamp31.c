#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A large island");
set_day_long("The island continues in all directions but the west where the plantlife has become so overgrown that travelling in that direction would be impossible.  The air is noticeably cooler here.");
set_night_long("The island continues in all directions but the west where the plantlife has become so overgrown that travelling in that direction would be impossible.  The air is noticeably cooler here.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"island": "You stand upon a large island.",
"plantlife": "The plantlife has completely overgrown the western portion of the island.",
]));
set_properties((["light" : 0, "night light" : 0,]));
set_exits(([

"northeast": SWAMP "swamp32.c",
"east": SWAMP "swamp30.c",
"south" : SWAMP "swamp29.c",

])); 
}
void reset() {
::reset(); 

if(!present("boar")) {
new(MOB "blackboar")->move(this_object());
}

ghast = random(100);
if ((ghast) > 94) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 96) { new(MOB "ghast")->move(this_object()); }
 }
}
}
