#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^West road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are on the Western road of Quixxiol.  Along the street you see houses of gold and more Merkkirri than you feel comfortable with.  To the north there is a general store and to the south the clerics hall.  The gnolls move about their business eyeing you suspiciously.%^RESET%^");
set_night_long("%^YELLOW%^You are on the Western road of Quixxiol.  Along the street you see houses of gold.  To the north there is a general store and to the south the clerics hall.  Whatever Merkkirri citizens you see tend to scamper away quickly.%^RESET%^");
set_items(([
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": GCITY "gcity6.c",
"west": GCITY "gcity12.c",
"north": GCITY "gcity25.c",
"south": GCITY "gcity24.c",
]));
}

void reset() {
 ::reset();
}
