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
set_long("%^BOLD%^BLACK%^The tunnel leads you to another cavern similar to the last one with four tunnels.  A rune is carved above the entrance to each tunnel here as well.  Strangely the way you came in seems to have disappeared.");
set_properties((["light" : 2, "indoors" : 1, "no teleport":1]));
set_exits(([
"west": DQUEST "dquest5.c",
"south": DQUEST "dquest6.c",
"east": DQUEST "dquest5.c",
"north": DQUEST "dquest5.c",
]));
set_items(([
"runes": "There is a rune carved above each tunnel entrance.  The one to the north is a %^BOLD%^RED%^red %^RESET%^warpike.  The one to the east a %^MAGENTA%^violet%^RESET%^ crown.  The tunnel to the south a %^BOLD%^BLUE%^blue%^RESET%^ skull.  The one to the west a %^BOLD%^GREEN%^green%^RESET%^ snake.",
"torches": "The torches are glowing with strange flames that dont seem to radiate heat of any kind.  You notice that the torch mounts are not actually fastened to the cave walls, but are magically suspended in air and are impossible to move.",
"walls": "The cave walls are rough and jagged yet the floor is strangely smooth.",
"floor": "The floor is covered with many strange runes.",
]));
}

void reset() {
::reset();
if(!present("weakness")) {
new(DQUEST "weakness.c")->move(this_object());
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
