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
      "How odd, this room looks positively normal.  Just a light carpet to greet muddy feet of vistors "
      "but none of the... quirks that Aime� puts in all of her other rooms.  Perhaps this is for the "
      "snobby merchant who doesn't like to have any fun?"
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
	"bedroom" : "The place to go once a room has been rented",
	"carpet" : "Wipe your feet!"
      ])
    );
    set_exits
    (([
	"out" : ROOMS"innthrfl2",
	"bedroom" : ROOMS"bedthrflroomw"

      ]));
    set_door("door", ROOMS"innthrfl2.c", "out", "keyring");
}
void reset() {
    ::reset();
    set_open("door", 0);
    set_locked("door", 1);
//    ROOMS"innthrfl2.c"->set_open("door", 0);
//    ROOMS"innthrfl2.c"->set_locked("door", 1);
}
