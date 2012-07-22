#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;
void init() {
    ::init();
}

void create() {
::create();
set_short("%^YELLOW%^A secret passage%^RESET%^");
set_long("%^YELLOW%^The passageway continues to the west.  You notice a strange %^MAGENTA%^violet%^YELLOW%^ light that softly reflects off the gold walls.  The source of the light is somewhere to the west.%^RESET%^");
set_items(([
]));
set_properties((["light" : 1, "indoors" : 1,]));
set_property("building",1);
set_exits(([
"south": GCITY "gcity74.c",
"west": GCITY "gcity76.c",
]));
}
void reset() {
 ::reset();
}
