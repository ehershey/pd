#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;
void init() {
    ::init();
}

void create() {
::create();
set_short("%^YELLOW%^Heart of the Blood Warriors%^RESET%^");
set_long("%^YELLOW%^This appears to be some sort of battle preparation room.  A table displays several crude maps and raid scenarios.  The room is pretty sparse otherwise.%^RESET%^");
set_items(([
"table":"The table displays several maps.",
"maps":"The maps are crude sketches made by the commanders to prepare for future village raids.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_property("building",1);
set_exits(([
"southeast": GCITY "secrettower6.c",
]));
}
void reset() {
 ::reset();
if(!present("gunthu")) {
new(MOB "gunthu.c")->move(this_object());
}
}
