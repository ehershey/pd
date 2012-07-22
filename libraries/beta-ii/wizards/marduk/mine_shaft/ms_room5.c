#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("goblin mine shaft");
    set_long("This area of the mines is abandoned.  Workers stripped the walls "
		"of it's precious minerals long ago.  The walls are rock hard "
		"and impossible for any more digging.  All that's left is a "
                "a small %^YELLOW%^torch%^RESET%^.");
    set_items(([
	"walls" : "The walls are rock hard.",
        "torch" : "A slowly fading %^%^YELLOW%^%^glow %^RESET%^%^comes from the torch."
    ]));
    set_properties(([
	"light" : 2,
        "night light" : 1
    ]));
    set_exits(([
        "west" : "/wizards/marduk/mine_shaft/ms_room3.c"
    ]));
}

void reset() {
  ::reset();
    if(!present("bandit"))
	new("/wizards/marduk/mine_shaft/bandit.c")->move(this_object());
}
