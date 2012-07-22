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
        set_day_long
        (
              "There is a giant portrait that dominates the room. It covers most of one wall and seems to be "
              "the only other then a window that would add any sort of decor to the room.  A small doorframe "
              "leads to the bedroom."  
        );
	    set_night_long
	    (
	    	"A single, solitary candle flickers upon being disturbed by the air that flows through "
	    	"the open door, casting shadows through out the room. The wall seems to be dominated by a dark black painting "
	    	"though it would be impossible to make it out in this light."
	    );
	    if (query_night())
	    {
	    	set_listen("default", "Light snoring can be heard");
	    	set_items
	        (
	                ([
	                        "windows" : "It's a window alright",
	                        "door" : "Good quailty oak",
	                        "bedroom" : "The place to go once a room has been rented",
	                   	    "painting" : "You can't make it out in this light",
				    ])
			);
	    }
	    else
	    {
	    	set_listen("default", "Birds chirping can be faintly heard");
	    	set_items
	        (
	                ([
	                        "windows" : "It's a window alright",
	                        "door" : "Good quailty oak",
	                        "bedroom" : "The place to go once a room has been rented",
	                   	    "portrait" : "So many %^BOLD%^%^RED%^c%^GREEN%^o%^BLUE%^l%^WHITE%^o%^CYAN%^r%^YELLOW%^s%^RESET%^ it gives you a headache just looking at it",
				    ])
			);
	    }
	    
        set_exits
        (([
                "out" : ROOMS"innthrfl3",
                "bedroom" : ROOMS"bedthrfle"
                
        ]));
set_door("door", ROOMS"innthrfl3.c", "out", "keyring");
}
void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
//ROOMS"innthrfl3.c"->set_open("door", 0);
//ROOMS"innthrfl3.c"->set_locked("door", 1);
}
