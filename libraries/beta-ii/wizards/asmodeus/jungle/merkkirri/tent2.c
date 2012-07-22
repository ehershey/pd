#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Guard's Barrack");
set_long("You have entered the barracks for the guards in this area.  It isn't very well kept and there are usually a few Merkkirri in here at any given time of day.  Beds line the tent where the guards sleep.");
set_properties((["light" : 3, "indoors" : 3,]));
set_exits(([
"out" : MJUNGLE "mjungle14.c",
]));
set_items(([
"beds" : "The barrack is full of a crude cots and blankets.",
"tent" : "The tent is well made and was woven by the Merkkirri.",
]));
}

void reset() {
::reset();
if(!present("guard")) {
new(MOB "gnollguard_sl.c")->move(this_object());
new(MOB "gnollguard_sl.c")->move(this_object());
new(MOB "gnollguard_sl.c")->move(this_object());
new(MOB "gnollguard_sl.c")->move(this_object());
}
}
