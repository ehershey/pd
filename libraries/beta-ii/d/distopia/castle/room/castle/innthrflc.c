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
        	"This must be the pottery room.  There are pots of all shapes and sizes everywhere! Even on the floor "
        	"because the pedestals are full.  It's kinda creepy really. None of them look like they are worth anything "
        	"though and they do add a certain crazy ambiance to the room.  A small line of candles near the ceiling keeps it fairly "
        	"well lit, probably to avoid someone from stumbling in and breaking a pot at night."
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
                        "pottery" : "Earthware clay pots in all shapes and sizes",
                        "pedestal" : "It's where the pots sit!"
                ])
        );
        set_exits
        (([
                "out" : ROOMS"innthrfl",
                "bedroom" : ROOMS"bedinnthrflc"
        ]));
set_door("door", ROOMS"innthrfl", "out", "keyring");
}
void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
//ROOMS"innthrfl.c"->set_open("door", 0);
//ROOMS"innthrfl.c"->set_locked("door", 1);
}
