#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^A hallway to the living quarters%^RESET%^");
set_day_long("%^YELLOW%^This hallway leads to the living quarters of the palace.  The ceiling of the hallway is made of an elaborate stained glass.  As the sun shines through the room is blasted in a %^BOLD%^RED%^c%^YELLOW%^o%^GREEN%^l%^ORANGE%^o%^CYAN%^r%^MAGENTA%^f%^WHITE%^u%^BLUE%^l%^RESET%^YELLOW%^ array.%^RESET%^");
set_night_long("%^YELLOW%^This hallway leads to the living quarters of the palace.  The ceiling of the hallway is made of an elaborate stained glass and makes for quite a sight during the daylight hours as the sun shines through it.%^RESET%^");
set_items(([
({"glass", "ceiling", "stained glass"}): "The stained glass is designed with a complicated pattern meant to capture the room in a psychadelic frenzy of color.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_property("building",1);
set_exits(([
"north" : GCITY "gcity50.c",
"south": GCITY "gcity63.c",
]));
}

void reset() {
 ::reset();
}

