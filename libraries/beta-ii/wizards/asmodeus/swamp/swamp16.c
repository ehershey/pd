#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("The lagoon");
set_day_long("You stand upon a small island within the swamp.  To the west you can see a larger body of land but no way of reaching it from here as it lies across from very deep water.");
set_night_long("You have wandered upon a small patch of land within the swamp.  The darkness is even more imposing this deep into the swamp.");
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

"east": SWAMP "swamp15.c",


])); 
}
void reset() {
::reset(); 
if(!present("boar")) {
new(MOB "blackboar")->move(this_object());

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
