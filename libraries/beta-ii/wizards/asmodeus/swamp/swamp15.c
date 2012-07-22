#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The lagoon");
set_day_long("The lagoon here is very shallow and stable ground doesn't look too far away.  Higher ground lies to the west while the swamp engulfs all other exits.");
set_night_long("The swamp has become very shallow here and you believe you can see higher ground to the west.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"lagoon": "The lagoon is rather small but could be deep.",
"water" : "The cool dark swamp water tests your footing.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"northwest": SWAMP "swamp14.c",
"west": SWAMP "swamp16.c",
"north": SWAMP "swamp13.c",
"northeast": SWAMP "swamp14.c",
"east": SWAMP "swamp17.c",
])); 
}
void reset() {
::reset(); 
if(!present("alligator")) {
new(MOB "alligator")->move(this_object());
new(MOB "alligator")->move(this_object());
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
