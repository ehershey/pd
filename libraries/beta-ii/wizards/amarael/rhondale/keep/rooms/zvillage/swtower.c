#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_name("Rhondale Southwest Tower");
     set_short("Rhondale Southwest Tower");
     set_long("The towers of Rhondale are nothing more than glorified watchpoints. Each of the other three towers is visible to the north, east and northeast. Should there be an emergency a guard will alert the town by activating a glowstone on the roof.");
     set_exits(([
                "down"		: KEEPROOM"zvillage/outer0730.c"
                ]));
     set_items(([
		"glowstone"	: "The glowstone is a simple rock that has been enchanted to emit a bright light when the correct command word is said."
		]));
}

void reset() {::reset();
     if (!present("monster")) {
        new(KEEPMOB"zvillage/watcher.c")->move(this_object());
        new(KEEPMOB"zvillage/watcher.c")->move(this_object());
        new(KEEPMOB"zvillage/watcher.c")->move(this_object());
        }
}
