#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A dark alcove");
set_day_long("You stand within a dark alcove.  Only the slightest amount of sunlight breaks through the lush jungle trees above.  Long slender vines droop lazily from the trees.");
set_night_long("You continue in a southern direction and find yourself surrounded by giant trees.  The water is shallow and you think travel to the southwest and southeast might be possible.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"vines" : "The vines entangle the trees and droop down into the shallow water.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"northeast": SWAMP "swamp8.c",
])); 
}
void reset() {
::reset(); 
if(!present("swamp devil")) {
new(MOB "swampdevil")->move(this_object());
new(MOB "swampdevil")->move(this_object());
}
ghast = random(100);
if ((ghast) > 97) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 98) { new(MOB "ghast")->move(this_object()); }
 }
}
}
