#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("north emmurd street");
        set_short("North Emmurd Street");
        set_long("North Emmurd Street passes by the cathedral before it ends, it is a street made of the finest cobble stone. The large cathedral lies to the west, its fine stained glass windows are a marvel to see. A solitary street light stands on the east side of the street. Several larger office buildings line the east side of the street, they stand only half as tall as the cathedral.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "street light"  :   "An old kerosene street lamp.",
            "cathedral"     :   "A large church with many elegant carvings.",
        ]));
        set_listen("default", "It is very quiet in this part of town.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"west"      : ROOMS "thrarandilChall2.c",
			"north"     : ROOMS "thrarandil043.c",
			"south"     : ROOMS "thrarandil045.c",
        ]));
        
}

