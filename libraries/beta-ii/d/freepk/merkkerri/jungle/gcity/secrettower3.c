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
set_long("%^YELLOW%^The passageway continues to the southwest.  You notice some torchlight coming from that area and the voices you heard before are much louder.  You continue or head back east in the direction you came.%^RESET%^");
set_listen("default", "You hear voices to the southwest.  They are much clearer than before.");
set_items(([
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_property("building",1);
set_exits(([
"east": GCITY "secrettower2.c",
"southwest": GCITY "secrettower6.c",
]));
}
int twist_hinge(string what) {
if (what != "hinge") return 0;
if (what == "hinge") {
message("info", "The wall slides aside revealing an exit out.\n", environment(this_player()));
add_exit(GCITY "gcity37.c", "out");
return 1;
}
}
void reset() {
 ::reset();
remove_exit("out");
}
