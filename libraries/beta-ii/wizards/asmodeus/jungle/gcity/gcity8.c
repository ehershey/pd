#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^South road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are on the Southern road of Quixxiol.  Along the street you see houses of gold and more Merkkirri than you feel comfortable with.  To the south lies the kataan and monk halls.  The square lies to the north.  The gnolls move about their business eyeing you suspiciously.%^RESET%^");
set_night_long("%^YELLOW%^You are on the Southern road of Quixxiol.  Along the street you see houses of gold.  To the north is the town square and to the south the monk and kataan halls.  Whatever Merkkirri citizens you see tend to scamper away quickly.%^RESET%^");
set_items(([
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"north": GCITY "gcity6.c",
"south": GCITY "gcity10.c",
]));
}

void reset() {
 ::reset();
}
