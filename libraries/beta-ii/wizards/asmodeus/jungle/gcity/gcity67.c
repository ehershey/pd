#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^A stairwell leading to the maids chamber%^RESET%^");
set_day_long("%^YELLOW%^You stand within a small stairwell that leads up to the quarters of the palace chambermaids.  Northeast will take you back to the mail hall of the living quarters.%^RESET%^");
set_night_long("%^YELLOW%^You stand within a small stairwell that leads up to the quarters of the palace chambermaids.  Northeast will take you back to the mail hall of the living quarters.%^RESET%^");
set_property("building",1);
set_items(([
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"up": GCITY "gcity78.c",
"northeast" : GCITY "gcity63.c",
]));
}

void reset() {
 ::reset();
}

