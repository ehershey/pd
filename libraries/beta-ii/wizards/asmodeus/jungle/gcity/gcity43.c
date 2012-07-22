#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Southwest area of the couryard%^RESET%^");
set_day_long("%^YELLOW%^The path bends to the south where a large golden guard tower stands.  The courtyard here still retains the same beauty as before.%^RESET%^");
set_night_long("%^YELLOW%^The path bends to the south where a large golden guard tower stands.  The courtyard here still retains the same beauty as before.%^RESET%^");
set_items(([
(({"flora", "plants"})) : "The plantlife is breathtaking.  Vibrant flowers and
sculpted bushes speckle the courtyard.",
(({"wildlife" , "birds", "insects"})) : "The wildlife in the courtyard is even
more diverse than the surrounding jungle!",
"towers" : "The towers shoot high up into the sky and overlooking the jungle.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"south": GCITY "gcity42.c",
"east": GCITY "gcity35.c",
]));
}

void reset() {
 ::reset();
}
