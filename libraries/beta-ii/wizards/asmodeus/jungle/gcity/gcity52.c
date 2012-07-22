#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^A hidden chamber behind the throne room%^RESET%^");
set_day_long("%^YELLOW%^The north wall in the throne room was merely an illusion!  You have entered a hidden chamber that appears to be used to keep a few of the Queen's valuables.  There are no other obvious exits.%^RESET%^");
set_night_long("%^YELLOW%^The north wall in the throne room was merely an illusion!  You have entered a hidden chamber that appears to be used to keep a few of the Queen's valuables.  There are no other obvious exits.%^RESET%^");
set_items(([
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"south": GCITY "gcity51.c",
]));
new(GCITY "treasure.c")->move(this_object());
}

void reset() {
 ::reset();
}

