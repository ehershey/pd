#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Top of the Northwest tower%^RESET%^");
set_day_long("%^YELLOW%^From the top of the Northwest tower you can see just how vast the jungle surrounding the city is.  Far off in the distance at the north end of the island you see a massive volcano and to the southeast the jungle gives way to a vast swamp.%^RESET%^");
set_night_long("%^YELLOW%^From the top of the Northwest tower you can see just how vast the jungle surrounding the city is.  Far off in the distance at the north end of the island you see a massive volcano and to the southeast the jungle gives way to a vast swamp.%^RESET%^");
set_items(([
"towers" : "The towers shoot high up into the sky and overlooking the jungle.",
"swamp" : "The swamp to the southeast is dark and uninviting.  Not even the Merkkirri venture within...",
"volcano" : "The volcano is quite active and has always been a part of Quixxiol's culture.",
"jungle" : "The surrounding jungle is much larger than you imagined.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"down" : GCITY "gcity54.c",
]));
}

void reset() {
 ::reset();
if (!present("royal guard")) {
new(MOB "royalguard")->move(this_object());
}
if(!present("vorath")) {
new (MOB "vorath")->move(this_object());
}
if (!present("tower guard")) {
new(MOB "swarmguard")->move(this_object());
new(MOB "swarmguard")->move(this_object());
   }
}

