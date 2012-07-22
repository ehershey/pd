#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^North road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are on the Northern road of Quixxiol.  Along the street %^YELLOW%^you see houses of gold and more Merkkirri than you feel %^YELLOW%^comfortable with.  To the south lies the town square and to %^YELLOW%^the north the fighter and mage halls.  The gnolls move about %^YELLOW%^their business eyeing you suspiciously.%^RESET%^");
set_night_long("%^YELLOW%^You are on the Northern road of Quixxiol.  Along the street you see houses of gold.  To the south is the town square and to the north the fighter and mage halls.  Whatever Merkkirri citizens you see tend to scamper away quickly.%^RESET%^");
set_items(([
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
//"north": GCITY "gcity9.c",
"south": GCITY "gcity6.c",
]));
}

void reset() {
 ::reset();
}
