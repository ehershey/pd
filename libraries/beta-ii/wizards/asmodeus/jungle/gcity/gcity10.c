#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^North road of Quixxiol%^RESET%^");
set_day_long("%^YELLOW%^You are on the Southern road of Quixxiol.  Along the street you see houses of gold and more Merkkirri than you feel comfortable with.  The kataan hall is to the west while the monk hall is to the east.  Going north will take you towards the town square.  The gnolls move about their business eyeing you suspiciously.%^RESET%^");
set_night_long("%^YELLOW%^You are on the Southern road of Quixxiol.  Along the street you see houses of gold.  The kataan hall is the the west while the monk hall is to the east.  Going north will take you towards the town square.  Whatever Merkkirri citizens you see tend to scamper away quickly.%^RESET%^");
set_items(([
"houses" : "The houses are made of solid %^BOLD%^YELLOW%^gold%^RESET%^.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": GCITY "gcity19.c",
"north": GCITY "gcity8.c",
"west": GCITY "gcity18.c",
]));
}

void reset() {
 ::reset();
}
