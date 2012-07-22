#include <gcity.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^West road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are on the Western road of Quixxiol.  Along the street %^YELLOW%^you see houses of gold and more Merkkirri than you feel %^YELLOW%^comfortable with.  To the north there is a stable and to the %^YELLOW%^south the shadowy rogue hall.  Further to the west at the end %^YELLOW%^of the Western road is a golden palace.  The gnolls move %^YELLOW%^about their business eyeing you suspiciously.%^RESET%^");
set_night_long("%^YELLOW%^You are on the Western road of Quixxiol.  Along the street %^YELLOW%^you see houses of gold.  To the north there is a stable and %^YELLOW%^to the south the shadowy rogue hall. Further to the west at %^YELLOW%^the end of the Western road is a golden palace.  Whatever %^YELLOW%^Merkkirri citizens you see tend to scamper away quickly.%^RESET%^");
set_items(([
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": GCITY "gcity11.c",
"west": GCITY "gcity15.c",
"north": GCITY "gcity13.c",
//"south": GCITY "gcity14.c",
]));
}

void reset() {
 ::reset();
}
