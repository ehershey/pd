#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^A stairwell leading to the queen's chamber%^RESET%^");
set_day_long("%^YELLOW%^You stand within a large stairwell leading high into the palace's tallest tower.  The Queen's bedroom resides at the top.  You can continue up the stairwell or back down to the main hall of the living quarters.%^RESET%^");
set_night_long("%^YELLOW%^You stand within a large stairwell leading high into the palace's tallest tower.  The Queen's bedroom resides at the top.  You can continue up the stairwell or back down to the main hall of the living quarters.%^RESET%^");
set_property("building",1);
set_items(([
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"up": GCITY "gcity80.c",
"down" : GCITY "gcity64.c",
]));
}

void reset() {
 ::reset();
}

