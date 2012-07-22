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
                "This room is remarkably bare.  The lack of any decor suggests that it might not be done "
                "or that perhaps Aime� went cheap.  Whatever the reason, there really isn't much to see "
                "here besides a small window and the entrance to the bedroom."
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
                        "bedroom" : "The place to go once a room has been rented"
                ])
        );
        set_exits
        (([
                "out" : ROOMS"innforfl",
                "bedroom" : ROOMS"bedforflc"
        ]));
set_door("door", ROOMS"innforfl", "out", "keyring");
}
void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
//ROOMS"innforfl.c"->set_open("door", 0);
//ROOMS"innforfl.c"->set_locked("door", 1);
}
