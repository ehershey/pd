#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Within the shallow swamp");
set_day_long("The water here is extremely shallow and reveals easy travel to the southwest and southeast.  Giant mold covered trees engulf you within their darkness.");
set_night_long("You continue in a southern direction and find yourself surrounded by giant trees.  The water is shallow and you think travel to the southwest and southeast might be possible.");
set_property("swamp",1);
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"sunbeams" : "Wooooooo..... nifty.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"southwest": SWAMP "swamp7.c",
"southeast": SWAMP "swamp10.c",
"west":SWAMP "swamp6.c",
])); 
}
void reset() {
::reset(); 
ghast = random(100);
if ((ghast) > 97) {
if (!present("ghast"))
     {
       new(MOB "ghast")->move(this_object());
if ((ghast) > 98) { new(MOB "ghast")->move(this_object()); }
 }
}
}
