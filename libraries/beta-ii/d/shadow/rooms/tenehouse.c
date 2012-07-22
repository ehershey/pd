#include <std.h>
inherit ROOM;
int lifted;
void create() {
   ::create();
     set_properties((["light": 0, "night light" : -1, "indoors" : 1]));
     set_short("House of Shadow");
     set_long("This delapidated old house is totally run down. The walls have many holes in them, the windows are smashed and the furniture is rotting. The floor is bare wood throughout, except in the corner where there is a small trapdoor.");
     set_exits(([
                "out"             : "/d/shadow/rooms/tene03.c"
                ]));
     set_items(([
		"trapdoor" : "The trapdoor is made of solid concrete, and has had writing etched into it that you could read.",
                "writing"  : "It would be possible to read it."
		]));
lifted = 0;
}

void init() {
   ::init();
	add_action("readin", "read");
        add_action("liftin", "lift");
}

int readin(string str) {
    if(str != "writing") return 0;
    message("info", "\nLift this door if you wish, but be warned. \nThe beast contained herein is born of the shadow. \nOnly the light of the sun can contain it's malice. \nWithout this light %^BOLD%^BLACK%^death%^RESET%^ is the price you shall pay.", this_player(), );
    message("info", this_player()->query_cap_name()+" reads the writing on the trap door.", this_object(), this_player());
    return 1;
}

int liftin(string str) {
    if(str != "door" && str != "trapdoor" && str != "trap door") return notify_fail("Lift what?\n");
    if(lifted == 1) return notify_fail("It's already open!\n");
    if (this_player()->query_level() < 50) return notify_fail("The trapdoor is locked, only those of great power may venture forth!\n");
    message("info", "As you lift the trapdoor a demonic wail assaults your ears. The way down is open.", this_player(), );
    message("indo", "As "+this_player()->query_cap_name()+" opens the trapdoor a demonic wail assaults your ears.", this_object(), this_player());
    add_exit("/d/shadow/rooms/teneshadow.c", "down");
    lifted = 1;
    call_out("rid_exit", 5);
    return 1;
}

void rid_exit() {
     message("info", "The trapdoor swings back and crashes closed.", this_object(), );
     remove_exit("down");
     lifted =0;
}
