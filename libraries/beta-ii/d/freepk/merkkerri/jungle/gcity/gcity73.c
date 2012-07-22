#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Top of the Southwest tower%^RESET%^");
set_day_long("%^YELLOW%^From the top of the Southwest tower you can see just how vast the jungle surrounding the city is.  Far off to the west and to the southwest the warm ocean waters glisten as they bathe in the sun.%^RESET%^");
set_night_long("%^YELLOW%^From the top of the Southwest tower you can see just how vast the jungle surrounding the city is.  Far off to the west and to the southwest the warm ocean waters glisten as they dance beneath the moon.%^RESET%^");
set_items(([
"towers" : "The towers shoot high up into the sky and overlooking the jungle.",
"jungle" : "The surrounding jungle is much larger than you imagined.",
"ocean":"The ocean reminds you of how seasick you get.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"down" : GCITY "gcity72.c",
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

