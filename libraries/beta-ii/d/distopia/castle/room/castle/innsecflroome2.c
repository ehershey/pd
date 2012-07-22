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
      "A great ticking in crescendo is heard as a great great many "
      "clocks line the walls.  Many different shapes, designs and "
      "colors.  Thankfully for the guests sanity, Aime� didn't purchase "
      "any Cookoo clocks, or else there really would be a violent incident"
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
	"hats" : "What a lot of hats... Hey, a Dick Tracey hat!"
      ])
    );
    set_exits
    (([
	"out" : ROOMS"innsecfl3",
	"bedroom" : ROOMS"bedsecflroomea"
      ]));
    set_door("door", ROOMS"innsecfl3.c", "out", "keyring");
}
void reset() {
    ::reset();
    set_open("door", 0);
    set_locked("door", 1);
//    ROOMS"innsecfl3.c"->set_open("door", 0);
//    ROOMS"innsecfl3.c"->set_locked("door", 1);
}
