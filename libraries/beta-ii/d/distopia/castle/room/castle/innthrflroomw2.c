#include <discastle.h>
inherit VAULT;
void create()
{
        ::create();
        set_properties
        (
(["light" : 3, "night light" : 3, "inside" : 1])
        );
        set_short("Mad Cow Tavern.");
        set_long
        (
			"This is the light room.  Big, bright lights come from seemingly "
			"everywhere at once, making it really hard to see.  The door leading "
			"to the bedroom is angled in such a way that the light will not reflect "
			"on the bed.  This one allowance by Aime� lets a guest get at least a "
			"little sleep... and it makes a great night light"
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
						"light" : "It's like daytime here"
                ])
        );
        set_exits
        (([
                "out" : ROOMS"innthrfl2",
                "bedroom" : ROOMS"bedthrflroomwa"
                
        ]));
set_door("door", ROOMS"innthrfl2.c", "out", "keyring");
}
void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
//ROOMS"innthrfl2.c"->set_open("door", 0);
//ROOMS"innthrfl2.c"->set_locked("door", 1);
}
