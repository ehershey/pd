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
      "This has to be the fur room.  There are pelts everywhere, shaped into every "
      "conceivable piece of fur rugging, blankets and fur towels.  Aime� must have "
      "cleared out Distopia forest to get this many pelts.  How'd she do it, anyway?"
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
	"fur" : "Oh look, a bear rug"
      ])
    );
    set_exits
    (([
	"out" : ROOMS"innsecfl2",
	"bedroom" : ROOMS"bedsecfl2a"
      ]));
    set_door("door", ROOMS"innsecfl2.c", "out", "keyring");
}
void reset() {
    ::reset();
    set_open("door", 0);
    set_locked("door", 1);
//    ROOMS"innsecfl2.c"->set_open("door", 0);
//    ROOMS"innsecfl2.c"->set_locked("door", 1);
}
