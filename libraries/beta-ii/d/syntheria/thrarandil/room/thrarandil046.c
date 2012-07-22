#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("stables");
        set_short("Stables");
        set_long("The stables of Thrarandil are not very large, but they are equip to handle many different kinds of mounts. Some of the strangest creatures known to exist can be seen here. The floor is covered with straw, it looks to be very fresh. On the wall are various farm tools, they are shiny and well maintained. In the corner is a large watering trough, filled to the brim with water.");  
        set_properties( ([ 
        "indoors"     : 1,
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "straw"         :   "Fresh straw that lines the ground.",
            "tools"         :   "A large assortment of tools, mostly pitchforks.",
        ]));
        set_listen("default", "It is very quiet in the stable.");
        set_smell("default", "The powerful odor of animal waste fills the air.");
        set_exits(([
			"southwest" : ROOMS "thrarandil070.c",
        ]));
        
}

