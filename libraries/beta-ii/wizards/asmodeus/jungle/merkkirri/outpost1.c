#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside a stone building");
set_long("You have entered the stone house that supports and shelters the guards.  The room is littered with trash and debris and a few make-shift cots have been constructed using cloth and logs.  A smaller doorway leads to the north room while the larger entrance leads out.");
set_properties((["light" : 3, "indoors" : 3,]));
set_exits(([
"out" : MJUNGLE "mjungle46.c",
"north" : MJUNGLE "outpost2.c",
]));
set_items(([
"cots" : "The cots are large enough to hold a gnoll and look quite uncomfortable.  However compared to the damp  stone floor they are quite luxurious.",
"tent" : "The tent is well made and was woven by the Merkkirri.",
]));
}

void reset() {
 ::reset();

if(!present("guard")) {
new(MOB "gnollguard_sl.c")->move(this_object());
new(MOB "gnollguard_sl.c")->move(this_object());
new(MOB "gnollguard_sl.c")->move(this_object());
}
}
