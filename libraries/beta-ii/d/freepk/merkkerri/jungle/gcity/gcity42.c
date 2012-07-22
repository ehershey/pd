#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Base of the Southwest tower%^RESET%^");
set_day_long("%^YELLOW%^The Southwest tower stands nearly identical to the Southeast tower and like the rest of the city, it is made of pure gold.  Merkkirri guards usually stand watch here.%^RESET%^");
set_night_long("%^YELLOW%^The Southwest tower stands nearly identical to the Southeast tower and like the rest of the city, it is made of pure gold.  Merkkirri guards usually stand watch here.%^RESET%^");
set_items(([
"towers" : "The towers shoot high up into the sky and overlooking the jungle.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"enter" : GCITY "gcity41.c",
"north": GCITY "gcity43.c",
]));
}

void reset() {
 ::reset();
if (!present("royal guard")) {
new(MOB "royalguard")->move(this_object());
}
if (!present("tower guard")) {
new(MOB "swarmguard")->move(this_object());
new(MOB "swarmguard")->move(this_object());
   }
}

