#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;
void create() {
::create();
set_short("Within the shallow swamp");
set_day_long("Darkness envelopes you from above as giant trees block nearly all the sunlight.  Here you see strange white birds high in the tree tops.  Looking down apon you.  Unimpressed, they fly away creating an almost muffled thunder.");
set_night_long("The swamp is nearly pitch black and travelling it is nearly impossible.  Sounds of strange animals shatter the deathly silence.");
set_property("swamp",1);
set_listen("default", "The occassional cry from an animal shatters the silence.");
set_items(([
"trees" : "The trees here are quite large and have thick, wide leaves that
block the majority of the sunlight.",
"birds" : "The birds were small and appeared harmless.",
"plantlife": "The plantlife here is quite extraordinary.  While the jungles to
the north and west are quite impressive, these plants are  many times larger
and occassionally even intelligent..",
]));
set_properties((["light" : 1, "night light" : 0,]));
set_exits(([
"west": SWAMP "swamp3.c",
"southeast":SWAMP "swamp9.c",
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
