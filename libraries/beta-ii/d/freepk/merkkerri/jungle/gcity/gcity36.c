#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Base of the Northeast tower%^RESET%^");
set_day_long("%^YELLOW%^The Northeast tower stands far taller than any other guard tower in the city.  It too is made entirely of gold.  Merkkirri guards usually stand watch here.%^RESET%^");
set_night_long("%^YELLOW%^The Northeast tower stands far taller than any other guard tower in the city.  It too is made entirely of gold.  Merkkirri guards usually stand watch here.%^RESET%^");
set_items(([
"towers" : "The towers shoot high up into the sky and overlooking the jungle.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"enter" : GCITY "gcity37.c",
"southwest": GCITY "gcity34.c",
]));
}

void reset() {
 ::reset();
if (!present("tower guard")) {
new(MOB "swarmguard")->move(this_object());
new(MOB "swarmguard")->move(this_object());
   }
}

