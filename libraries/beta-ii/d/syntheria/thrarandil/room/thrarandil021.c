#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("irminric circle street");
        set_short("Irminric Circle Street");
        set_long("Irminric Circle Street encircles the southern half of Thrarandil, it is heavily travelled by both people and cart. Large buildings line the street, they look to be warehouses. Each building is made of wood, and has no windows. Many large barrels are stacked in front of the buildings, many hold alcohol of various types imported from all over the world.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "buildings"     :   "Large wooden structures made of wood, used to warehouse imported goods.",
            "barrels"       :   "Large wooden barrels reinforced with metal bands, they hold alcohol imported from all over the world.",
        ]));
        set_listen("default", "Only the sounds of people walking on the road can be heard.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"east"		: ROOMS "thrarandil020.c",
			"west"      : ROOMS "thrarandil022.c",
        ]));
        
}

