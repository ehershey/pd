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
set_long("%^YELLOW%^The passageway continues to the west.  You notice some torchlight coming from that area as well as voices.  You can also go back up the stairs.%^RESET%^");
set_listen("default", "You hear voices to the west.  They speak in Merkish.");
set_items(([
"stairs":"The stairs lead back to the beginning of the passageway.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_property("building",1);
set_exits(([
"up": GCITY "secrettower1.c",
"west": GCITY "secrettower3.c",
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
