#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Within the Southeast guard tower%^RESET%^");
set_long("%^YELLOW%^The stairs continue upwards to top of the tower or you can go down to the lounge level.%^RESET%^");
set_items(([
"stairs":"The stairs lead up into the higher levels of the tower.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"down": GCITY "gcity68.c",
"up": GCITY "gcity70.c",
]));
}

void reset() {
 ::reset();
}
