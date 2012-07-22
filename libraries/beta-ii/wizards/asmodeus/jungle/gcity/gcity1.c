#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^East road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are at the East Gate of Quixxiol.  The Merkkirri jungle dominates the region outside of this gate.  Along the street you see houses of gold and more Merkkirri than you feel comfortable with.  The gnolls move about their business eyeing you suspiciously.%^RESET%^");
set_night_long("%^YELLOW%^You are at the East Gate of Quixxiol.  The Merkkirri jungle dominates the region outside of this gate.  Along the street you see houses of gold and their inhabitants inside.  An occassional Merkkirri can be seen wandering the streets drunk.%^RESET%^");
set_items(([
"gateway" : "The gateway is made of %^BOLD%^YELLOW%^gold%^RESET%^ as is the entire city.",
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
]));
set_properties((["light" : 2, "night light" : 2,]));
new(MJUNGLE "gateway.c")->move (this_object());
set_exits(([
"west": GCITY "gcity2.c",
"gateway": MJUNGLE "mjungle48.c",
]));
}

void reset() {
 ::reset();
if(!present("guard")) {
new(MOB "gnollguardb.c")->move (this_object());
new(MOB "gnollguardb.c")->move (this_object());
}
}
