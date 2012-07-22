#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The lagoon");
set_day_long("You enter the thick of the swamp once again and find that it opens up more to the southwest.  The sun is almost completely blocked by the giant swamp trees.");
set_night_long("You enter the thick of the swamp once again and find that it opens up more to the southwest.  The sporadic cry of a strange beast can be heard off in the distance.");
set_listen("default", "You hear a strange howl off to the east.");
set_smell("default", "The air here is stale and smells of mold.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"water" : "The cool dark swamp water tests your footing.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"southwest": SWAMP "swamp24.c",
"northwest": SWAMP "swamp17.c",
])); 
}
void reset() {
::reset(); 
if(!present("tangleweed")) {
new(MOB "tangleweed")->move(this_object());
new(MOB "tangleweed")->move(this_object());
new(MOB "tangleweed")->move(this_object());
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
