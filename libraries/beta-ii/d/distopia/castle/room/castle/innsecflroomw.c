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
			"This must have been the room where Aime� decided to use every single color in the entire world "
			"the walls are a mulitude of %^RED%^reds%^RESET%^, %^GREEN%^greens%^RESET%^, and%^BLUE%^ blues%^RESET%^.  It's enough to give anyone "
			"a headache!"
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
                        "walls" : "Ugh... head hurt"
                ])
        );
        set_exits
        (([
                "out" : ROOMS"innsecfl2",
                "bedroom" : ROOMS"bedsecfl2"
        ]));
set_door("door", ROOMS"innsecfl2.c", "out", "keyring");
}
void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
//ROOMS"innsecfl2.c"->set_open("door", 0);
//ROOMS"innsecfl2.c"->set_locked("door", 1);
}
