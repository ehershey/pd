#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("A shallow path");
set_day_long("Thick plantlife grows to the north of you and swamp water borders you to the south.  You see a slightly worn trail heading to the east.");
set_night_long("The dark swamp is nearly impossible to traverse yet you somehow manage.  A faint trail leads to the east.  The chilling silence is broken only by the cry of the occassional animal.");
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

"northwest": SWAMP "swamp4.c",
"east": SWAMP "swamp35.c",
])); 
}
void reset() {
::reset(); 
if(!present("tangleweed")) {
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
