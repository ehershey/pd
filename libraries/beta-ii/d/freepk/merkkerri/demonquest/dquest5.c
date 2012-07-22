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
set_short("%^BOLD%^CYAN%^The swirling madness of chaos!%^RESET%^");
set_long("%^BOLD%^BLACK%^ROARS OF LAUGHTER%^BOLD%^CYAN%^ echo through your mind as you realize something is wrong.
You are floating in the swirling madness of the chaos dimension.  This is the home of some of the nastiest creatures in the universe.  Asmodeus does not take well to failure as you are about to learn...%^RESET%^");
set_properties((["light" : 2, "indoors" : 1, "no teleport":1]));
set_exits(([
]));
set_items(([
"torches": "The torches are glowing with strange flames that dont seem to radiate heat of any kind.  You notice that the torch mounts are not actually fastened to the cave walls, but are magically suspended in air and are impossible to move.",
"floor": "The floor is covered with many strange runes.",
]));
}

void reset() {
::reset();
if(!present("demon")) {
new(DQUEST "c_demon.c")->move(this_object());
new(DQUEST "c_demon.c")->move(this_object());
new(DQUEST "c_demon.c")->move(this_object());
}
}
int survey(string what) {
write("Your mind is unable to focus.");
    return 1;
}

int peer(string what) {
write("Your mind is unable to focus.");
    return 1;
}
