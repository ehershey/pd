#include <mjungle.h>
#include <std.h>
inherit VAULT;

void create() {
    ::create();
    set_short("End of a tunnel");
    set_long("You have come to the end of a tunnel that goes back south.  To the east and west of you there are rooms and to the north there is a massive wooden door with thick iron hinges.");
    set_items(([
        "tunnel" : "The tunnel is dark and cool.  Who knows where it might lead.",
        "door": "The door stands nearly eight feet tall and has thick iron hinges.  There is a keyhole beneath the handle.",
        "keyhole" : "Looks like a key might fit in it.  What do you think?",
      ]));
    set_properties((["light" : 2, "night light" : 2,]));
    set_exits(([
        "east": MJUNGLE "tomb17",
        "north": MJUNGLE "tomb20",
        "south": MJUNGLE "tomb9",
        "west": MJUNGLE "tomb19",
      ]));
    set_door("door", MJUNGLE "tomb20", "north", "crypt key");
    set_string("door", "open", "A rush of warm air and the stench of death flood the room as you open the door.");
    set_open("door", 0);
    set_locked("door", 1);
}

void reset() {
    ::reset();
    set_open("door", 0);
    set_locked("door", 1);
    get_object(MJUNGLE "tomb20.c")->set_open("door", 0);
    get_object(MJUNGLE "tomb20.c")->set_locked("door", 1);
}
