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
set_short("A cave lit by several torches");
set_long("%^BOLD%^BLACK%^You have been magically teleported to another cavern.  Four tunnels lead from this cavern and the only thing that distinguishes one from another is the runes carved above the entrance to each tunnel.%^RESET%^");
set_smell("default", "The cave smells of decay.");
set_listen("default", "You hear voices mumble but you are not sure they are real or in you mind.");
set_properties((["light" : 2, "indoors" : 1, "no teleport":1]));
set_exits(([
"southwest": DQUEST "dquest5.c",
"southeast": DQUEST "dquest5.c",
"northwest": DQUEST "dquest4.c",
"northeast": DQUEST "dquest5.c",
]));
set_items(([
"runes": "There is a rune carved above each tunnel entrance.  The one to the northwest is a %^BOLD%^RED%^red %^RESET%^ram's head.  The one to the northeast a %^YELLOW%^golden%^RESET%^ crown.  The tunnel to the southwest of a %^BOLD%^BLACK%^black%^RESET%^ skull and the southeast the %^GREEN%^green%^RESET%^ face of a demon.",
"torches": "The torches are glowing with strange flames that dont seem to radiate heat of any kind.  You notice that the torch mounts are not actually fastened to the cave walls, but are magically suspended in air and are impossible to move.",
"walls": "The cave walls are rough and jagged yet the floor is strangely smooth.",
"floor": "The floor is covered with many strange runes.",
]));
}

void reset() {
::reset();
if(!present("joy")) {
new(DQUEST "joy.c")->move(this_object());
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
