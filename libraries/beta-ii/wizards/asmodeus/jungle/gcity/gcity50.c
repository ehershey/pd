#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Hall leading to living quarters%^RESET%^");
set_day_long("%^YELLOW%^You have entered a hallway leading to the living quarters of the palace.  You can go south towards these rooms or back northeast to the entrance hall.%^RESET%^");
set_night_long("%^YELLOW%^You have entered a hallway leading to the living quarters of the palace.  You can go south towards these rooms or back northeast to the entrance hall.%^RESET%^");
set_property("building",1);
set_items(([
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"northeast" : GCITY "gcity47.c",
"south": GCITY "gcity62.c",
]));
}

void reset() {
 ::reset();
}

