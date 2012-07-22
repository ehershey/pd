#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Within the Northwest guard tower%^RESET%^");
set_long("%^YELLOW%^The lower section of the tower is mostly reserved for weapons and minor supplies.  There is also a rotting wooden table located in the middle of the room.  A set of stairs spirals up along the circular wall of the tower.%^RESET%^");
set_items(([
"stairs":"The stairs lead up into the higher levels of the tower.",
"table":"The wooden table is old and rotting.  It looks to be used for the guards to eat upon.",
(({"supplies", "weapons"})): "The weapons and supplies aren't worth noting.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"out": GCITY "gcity45.c",
"up": GCITY "gcity54.c",
]));
}

void reset() {
 ::reset();
}
