#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;
void init() {
    ::init();
add_action("twist_hinge" , "twist");
}

void create() {
::create();
set_short("%^YELLOW%^A secret passage%^RESET%^");
set_long("%^YELLOW%^You have stumbled upon a secret passage that leads to a set of stairs going down.  A torch is mounted upon an iron hinge on the east wall.%^RESET%^");
set_items(([
"stairs":"The stairs lead into the darkness below.",
"torch": "A single torch and a hinge made of iron.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_property("building",1);
set_exits(([
"down": GCITY "secrettower2.c",
]));
}
int twist_hinge(string what) {
if (what != "hinge") return 0;
if (what == "hinge") {
message("info", "The wall slides aside revealing an exit out.\n", environment());
add_exit(GCITY "gcity37.c", "out");
return 1;
}
}
void reset() {
 ::reset();
remove_exit("out");
}
