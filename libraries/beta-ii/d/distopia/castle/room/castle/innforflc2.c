#include <discastle.h>
inherit VAULT;
void create()
{
    ::create();
    set_properties
    (
      (["light" : 2, "night light" : 2, "inside" : 1])
    );
    set_short("Mad Cow Tavern.");
    set_long
    (
      "Wow! This room is plated in what looks like solid gold! Everything "
      "from the walls to the floor has at least a gold tint over it.  Pillars "
      "that support this room look like they are made out of totally gold. This must "
      "be where all the rich mercants sleep.  To bad you can't take anything."
    );

    if (query_night())
    {
	set_listen("default", "Light snoring can be heard");
    }
    else
    {
	set_listen("default", "Birds chirping can be faintly heard");
    }
    set_items
    (
      ([

	"windows" : "It's a window alright",
	"door" : "Good quailty oak",
	"bedroom" : "The place to go once a room has been rented"
      ])
    );
    set_exits
    (([
	"out" : ROOMS"innforfl",
	"bedroom" : ROOMS"RICHbedforflc"
      ]));
    set_door("door", ROOMS"innforfl", "out", "keyring");
}
void reset() {
    ::reset();
    set_open("door", 0);
    set_locked("door", 1);
//    ROOMS"innforfl.c"->set_open("door", 0);
//    ROOMS"innforfl.c"->set_locked("door", 1);
}
