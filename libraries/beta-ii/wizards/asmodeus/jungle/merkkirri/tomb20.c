#include <mjungle.h>
#include <std.h>
inherit VAULT;

void create() {
::create();
set_short("Inside the Warchief's Tomb");
set_long("This room houses only one corpse--the mighty warchief.  The warchief is possibly more dangerous now than he was during life.");
set_items(([
"door": "The door stands nearly eight feet tall and has thick iron hinges.  There is a keyhole beneath the handle.",
"keyhole" : "Looks like a key might fit in it.  What do you think?",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"south": MJUNGLE "tomb11.c",
]));
set_door("door", MJUNGLE "tomb11.c", "south", "crypt key");
set_string("door", "open", "The door creaks loudly as you open it.");
}

void reset() {
::reset();
set_open("door", 0);
set_locked("door", 1);
MJUNGLE "tomb11.c"->set_open("door", 0);
MJUNGLE "tomb11.c"->set_locked("door", 1);
if(!present("chief"))
new(MOB "unchief")->move(this_object());
}
