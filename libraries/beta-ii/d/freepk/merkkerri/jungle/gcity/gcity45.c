#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Base of the Northwest tower%^RESET%^");
set_day_long("%^YELLOW%^The Northwest tower stands slightly shorter and wider than its counterparts and like the rest of the city, it is made of pure gold.  Merkkirri guards usually stand watch here.%^RESET%^");
set_night_long("%^YELLOW%^The Northwest tower stands slightly shorter and wider than its counterparts and like the rest of the city, it is made of pure gold.  Merkkirri guards usually stand watch here.%^RESET%^");
set_items(([
"towers" : "The towers shoot high up into the sky and overlooking the jungle.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"enter" : GCITY "gcity46.c",
"south": GCITY "gcity44.c",
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

