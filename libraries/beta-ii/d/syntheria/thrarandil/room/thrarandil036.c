#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("karisos street");
        set_short("Karisos Street");
        set_long("Karisos Street runs north to south on the west side of town, the street ends here. There is a small dirt path to the northeast, it goes around the back of the cathedral. This part of Karisos Street isn't travelled much, the only item of interest along this part of the street is the cathedral to the southeast. Being this close to the cathedral doesn't allow for a full viewing of the massive structure. To the west is a steep cliff which leads down to the sea, the cliff looks far too steep to be able to get down to the sea.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "cathedral"     :   "A large church with many elegant carvings.",
            "cliff"         :   "A steep cliff, it meets the sea.",
        ]));
        set_listen("default", "It is very quiet in this part of town.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"northeast" : ROOMS "thrarandil037.c",
			"south"     : ROOMS "thrarandil035.c",
        ]));
        
}

