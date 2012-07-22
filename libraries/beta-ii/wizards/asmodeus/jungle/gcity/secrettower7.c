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
set_long("%^YELLOW%^This room has been set aside as the Warlord's personal study.  Like the other battle preparation rooms, this one also has a table with maps displayed atop it.  Sahuun's chamber is sparsely decorated.%^RESET%^");
set_items(([
"table":"The table displays several maps.",
"maps":"The maps are crude sketches made by the commanders to prepare for future village raids.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_property("building",1);
set_exits(([
"west": GCITY "secrettower6.c",
]));
}
void reset() {
 ::reset();
if(!present("sahuun")) {
new(MOB "sahuun.c")->move(this_object());
}
}
