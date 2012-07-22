#include <mjungle.h>
#include <std.h>
#include <dquest.h>
inherit ROOM;

void init() {
  ::init();
add_action("peer", "peer");
add_action("survey", "survey");
}

void create() {
::create();
set_short("A maddening maze");
set_long("%^BOLD%^BLACK%^You have been transported to entrance of an enormous maze.  It is here that sadists, lunatics, the demented, and the like come to abandon life as we know it and surrender their souls forever in promise of demonic power.  Asmodeus takes great pleasure in torturing the souls of those who wish to attain demon status and has gone to great lengths to be sure only the best succeed in this endeavor.%^RESET%^");

set_properties((["light" : 2, "indoors" : 1,]));
set_exits(([
"northeast": DQUEST "dquest105.c",
]));
set_items(([
"walls": "The walls are made of a smooth black stone and have very few if any distinguishing marks.",
]));
}

void reset() {
::reset();
}
int survey(string what) {
write("Your mind is unable to focus.");
    return 1;
}

int peer(string what) {
write("Your mind is unable to focus.");
    return 1;
}
