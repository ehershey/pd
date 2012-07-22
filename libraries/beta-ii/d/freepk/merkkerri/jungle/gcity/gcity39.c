#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Within the Southeast guard tower%^RESET%^");
set_long("%^YELLOW%^The lower section of the tower is mostly reserved for weapons and minor supplies.  A set of stairs spirals up along the circular wall of the tower.%^RESET%^");
set_items(([
"stairs":"The stairs lead up into the higher levels of the tower.",
(({"supplies", "weapons"})): "The weapons and supplies aren't worth noting.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_property("building",1);
set_exits(([
"out": GCITY "gcity38.c",
"up": GCITY "gcity68.c",
]));
}

void reset() {
 ::reset();
}
