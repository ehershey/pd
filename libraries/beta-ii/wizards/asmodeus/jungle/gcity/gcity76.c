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
set_long("%^YELLOW%^The passageway continues to the northwest.  You notice the strange %^MAGENTA%^violet%^YELLOW%^ light is brighter here.  The source of the light is coming from the room to the northwest...%^RESET%^");
set_items(([
]));
set_properties((["light" : 1, "indoors" : 1,]));
set_property("building",1);
set_exits(([
"east": GCITY "gcity75.c",
"northwest": GCITY "gcity77.c",
]));
}
void reset() {
 ::reset();
}
