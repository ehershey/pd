#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Hall leading to the dining area%^RESET%^");
set_day_long("%^YELLOW%^You have entered a hallway leading to the kitchen and dining areas of the palace.  You can go north into the dining hall, east into the kitchen or southeast towards the entrance chamber.%^RESET%^");
set_night_long("%^YELLOW%^You have entered a hallway leading to the kitchen and dining areas of the palace.  You can go north into the dining hall, east into the kitchen or southeast towards the entrance chamber.%^RESET%^");
set_items(([
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"north" : GCITY "gcity60.c",
"east": GCITY "gcity61.c",
"southeast" : GCITY "gcity47.c",
]));
}

void reset() {
 ::reset();
}

