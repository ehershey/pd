#include <gcity.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^East road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are on the Eastern road of Quixxiol.  Along the street %^YELLOW%^you see houses of gold and more Merkkirri than you feel %^YELLOW%^comfortable with.  To the north there is a magic shop and to %^YELLOW%^the south an store of healing.  The gnolls move about their %^YELLOW%^business eyeing you suspiciously.%^RESET%^");
set_night_long("%^YELLOW%^You are on the Eastern road of Quixxiol.  Along the street %^YELLOW%^you see houses of gold.  To the north there is a magic shop %^YELLOW%^and to the south a house of healing.  Whatever Merkkirri %^YELLOW%^citizens you see tend to scamper away quickly.%^RESET%^");
set_items(([
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": GCITY "gcity2.c",
"west": GCITY "gcity6.c",
"north": GCITY "gcity22.c",
"south": GCITY "gcity23.c",
]));
}

void reset() {
 ::reset();
}