#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^North road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are on the Northern road of Quixxiol.  Along the street you see houses of gold and more Merkkirri than you feel comfortable with.  The fighter hall is to the west while the mage hall is to the east.  Going south will take you towards the town square.  The gnolls move about their business eyeing you suspiciously.%^RESET%^");
set_night_long("%^YELLOW%^You are on the Northern road of Quixxiol.  Along the street you see houses of gold.  The fighter hall is the the west while the mage hall is to the east.  Goin south will take you towards the town square.  Whatever Merkkirri citizens you see tend to scamper away quickly.%^RESET%^");
set_items(([
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": GCITY "gcity20.c",
"south": GCITY "gcity7.c",
"west": GCITY "gcity17.c",
]));
}

void reset() {
 ::reset();
}
