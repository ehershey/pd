#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("irminric circle street");
        set_short("Irminric Circle Street");
        set_long("The intersection of Irminric Circle Street and Karisos Street is here. Irminric Circle Street encircles the southern half of Thrarandil. The street is made of worn cobblestone, it looks to be very old. Some small buildings line the street, they are the homes of the many workers of the city. Each building has a small window looking out into the street. The homes are made of wood and brick, a sharp contrast to the large stone buildings of the inner city.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "buildings"     :   "Small homes for all the workers. Each home has little window that looks out onto the steet.",
        ]));
        set_listen("default", "Only the sounds of people walking on the road can be heard.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"north"		: ROOMS "thrarandil019.c",
			"east"		: ROOMS "thrarandil011.c",
			"west"      : ROOMS "thrarandil021.c",
        ]));
        
}

