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
      "This is the fish room.  There are fish tanks everywhere! And all sorts of "
      "fish in them.  Aime� must have an army to take care of all these fish and "
      "the tanks.  It's actually kind of relaxing, though... Especially the bright "
      "colors of the tropical fish"
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
	"fish" : "Glub glub!"
      ])
    );
    set_exits
    (([
	"out" : ROOMS"innsecfl",
	"bedroom" : ROOMS"bedsecflc"
      ]));
    set_door("door", ROOMS"innsecfl", "out", "keyring");
}
void reset() 
{
    ::reset();
    set_open("door", 0);
    set_locked("door", 1);
//    ROOMS"innsecfl.c"->set_open("door", 0);
//    ROOMS"innsecfl.c"->set_locked("door", 1);
}
