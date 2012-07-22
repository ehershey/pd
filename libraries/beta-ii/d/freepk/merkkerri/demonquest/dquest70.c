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
set_short("");
set_long("");
set_properties((["light" : 2, "indoors" : 1, "no teleport":1]));
set_exits(([
"northwest": DQUEST "dquest73.c",
"southeast": DQUEST "dquest53.c",
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
