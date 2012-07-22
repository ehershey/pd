#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Within the Northwest guard tower%^RESET%^");
set_long("%^YELLOW%^The middle section of the tower has been converted into a makeshift rest area.  Guards often drink or gamble here to pass time while off duty.%^RESET%^");
set_items(([
"stairs":"The stairs lead up into the higher levels of the tower.",
"table":"The wooden table is old and rotting.  It looks to be used for the guards to eat upon.",
(({"supplies", "weapons"})): "The weapons and supplies aren't worth noting.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"down": GCITY "gcity46.c",
"up": GCITY "gcity55.c",
]));
}

void reset() {
 ::reset();
}
