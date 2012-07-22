#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A trail along the swamp");
set_day_long("The trail extends to the west and southest.  A large rockface blocks passage to the north and deep swamp waters block passage to the south.  The sounds of wildlife flood this part of the swamp.");
set_night_long("The trail extends to the west and southeast although it is faint and hard to follow in the dark.  The murky swamp waters all but glisten from the moon above as thick slime coats the waters surface.  Strange swamp critters click and chatter with eerie noises all around.");
set_property("swamp",1);
set_items(([
"trail" : "The trail is faint and appears to have very infrequent use.  It might just be the path left by a large predator.",
"water" : "The swamp is just to the south of you and is coated with slime.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
"rockface" : "The rockface looks natural and is far too steep to climb.",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([

"southeast": SWAMP "swamp38.c",
"west" : SWAMP "swamp35.c",

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
