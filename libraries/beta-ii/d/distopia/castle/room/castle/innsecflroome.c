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
			"Hats! Hats everywhere.  Big hats, small hats, medium sized hats that fit well on a Raknid "
			"what a lot of hats.  And not one of them looks like it'd be useful for any time of armor. "
			"Where did she get all these hats?  There is even a candle in the shape of a hat, giving a "
			"cheerful illumination to the room around the clock."
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
                "bedroom" : ROOMS"bedsecflroome"
        ]));
set_door("door", ROOMS"innsecfl3.c", "out", "keyring");
}
void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
//ROOMS"innsecfl3.c"->set_open("door", 0);
//ROOMS"innsecfl3.c"->set_locked("door", 1);
}
