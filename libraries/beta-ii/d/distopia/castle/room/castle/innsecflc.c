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
			"AHH!! Oh...wait... It's only a giant moose head...with candles in it's nose. "
			"Actually, it provides pretty good illumination, but what the hell was "
			"Aime� thinking?  Sometimes people wonder about her."
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
						
                ])
        );
 		set_exits
        (([
                "out" : ROOMS"innsecfl",
               "bedroom" : ROOMS"bedsecflca"
        ]));
set_door("door", ROOMS"innsecfl", "out", "keyring");
}
void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
//ROOMS"innsecfl.c"->set_open("door", 0);
if(!present("moosehead"))
{
	new(ITEMS"moosehead")->move(this_object());
}
//ROOMS"innsecfl.c"->set_locked("door", 1);
}
