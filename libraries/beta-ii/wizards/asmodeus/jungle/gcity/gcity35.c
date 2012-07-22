#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^South area of the couryard%^RESET%^");
set_day_long("%^YELLOW%^The path here forks to two towers.  One watching the southeastern jungle, the other the southwestern.  These towers are often referred to as the 'twins' due to their similar size and shape.  The courtyard here remains just as amazing as the rest.%^RESET%^");
set_night_long("%^YELLOW%^The path here forks to two towers.  One watching the southeastern jungle, the other the southwestern.  These towers are often referred to as the 'twins' due to their similar size and shape.  The courtyard here remains just as amazing as the rest.%^RESET%^");
set_items(([
(({"flora", "plants"})) : "The plantlife is breathtaking.  Vibrant flowers and
sculpted bushes speckle the courtyard.",
(({"wildlife" , "birds", "insects"})) : "The wildlife in the courtyard is even
more diverse than the surrounding jungle!",
"towers" : "The towers shoot high up into the sky and overlooking the jungle.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"southeast": GCITY "gcity38.c",
"north": GCITY "gcity21.c",
"west": GCITY "gcity43.c",
]));
}

void reset() {
 ::reset();
}
