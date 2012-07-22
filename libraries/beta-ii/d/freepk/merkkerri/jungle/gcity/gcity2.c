#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^East road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are on the Eastern road of Quixxiol.  Along the street %^YELLOW%^you see houses of gold and more Merkkirri than you feel %^YELLOW%^comfortable with.  To the north there is a bar and to the %^YELLOW%^south a hospital.  The gnolls move about their business %^YELLOW%^eyeing you suspiciously.%^RESET%^");
set_night_long("%^YELLOW%^You are on the Eastern road of Quixxiol.  Along the street %^YELLOW%^you see houses of gold.  To the north there is a bar and to %^YELLOW%^the south a hospital.  Whatever Merkkirri citizens you see %^YELLOW%^tend to scamper away quickly.%^RESET%^");
set_items(([
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": GCITY "gcity1.c",
"west": GCITY "gcity5.c",
"north": GCITY "gcity3.c",
"south": GCITY "gcity4.c",
]));
}

void reset() {
 ::reset();
}
