#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("a secret room");
    set_long("%^BOLD%^%^BLACK%^This is the storage room of the Chimeras. The room is littered;with bones and skulls. The only exit appears to be a ladder.");
    set_items(([
        "ladder" : "You probably could use this to climb out of here.",
    ]));
    set_properties(([
        "light" : 1,
    ]));
}

void reset() {
    if(!present("chimera"))
        new("/wizards/marduk/hell/chimera.c")->move(this_object());
        new("/wizards/marduk/hell/chimera.c")->move(this_object());
        new("/wizards/marduk/hell/chimera.c")->move(this_object());
        new("/wizards/marduk/hell/chimera.c")->move(this_object());
        new("/wizards/marduk/hell/chimera.c")->move(this_object());
        new("/wizards/marduk/hell/chimera.c")->move(this_object());
}

void init() {
::init();
add_action("func_climb", "climb");
}
int func_climb(string str) {
if (!str || str=="") return notify_fail("Climb what?\n");
write("You climb the ladder.");
this_player()->move_player("/wizards/marduk/hell/h_room3.c", "up the ladder");
return 1;
}
