#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Within the Southwest guard tower%^RESET%^");
set_long("%^YELLOW%^This section of the tower is used as a resting place for the guards who are off duty.  Cots have been set up as well somewhat comfortable chairs.  A table rests in the center of the room.%^RESET%^");
set_items(([
"stairs":"The stairs lead up into the higher levels of the tower.",
"table":"The wooden table is old and rotting.  It looks to be used for the guards to eat upon.",
"cots":"The cots look relaxing.",
"chairs":"They probably do the job.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"down": GCITY "gcity41.c",
"up": GCITY "gcity72.c",
]));
}

void reset() {
 ::reset();
}
