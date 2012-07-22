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
      "This must be the music room.  There are musical instruments everywhere.  From lutes, "
      "to flutes there seems to be every conceivable instrument here.  What's more it looks like "
      "they have been broken in and can be easily played... If only you knew how."
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
	"instruments" : "You wouldn't want to take them. Aime� would get mad",
	"lute" : "It's a string instrument",
	"flute" : "You blow on it and it makes sound"
      ])
    );
    set_exits
    (([
	"out" : ROOMS"innthrfl",
	"bedroom" : ROOMS"bedinnthrflca"
      ]));
    set_door("door", ROOMS"innthrfl", "out", "keyring");
}
void reset() {
    ::reset();
    set_open("door", 0);
    set_locked("door", 1);
//    ROOMS"innthrfl.c"->set_open("door", 0);
//    ROOMS"innthrfl.c"->set_locked("door", 1);
}
