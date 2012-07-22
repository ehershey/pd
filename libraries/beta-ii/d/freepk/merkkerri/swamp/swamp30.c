#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A large island");
set_day_long("The island continues in all directions but the east where the dark swamp water looks quite forbidding.  The air is noticeably cooler here.");
set_night_long("The island continues in all directions but the east where the dark swamp water looks quite forbidding.  The air is noticeably cooler here.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"island": "You stand upon a large island.",
"water": "The cold swamp water looks far too deep to cross.",
]));
set_properties((["light" : 0, "night light" : 0,]));
set_exits(([

"north": SWAMP "swamp32.c",
"west": SWAMP "swamp31.c",
"southwest" : SWAMP "swamp29.c",

])); 
}
void reset() {
::reset(); 


ghast = random(100);
if ((ghast) > 94) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 96) { new(MOB "ghast")->move(this_object()); }
 }
}
}
