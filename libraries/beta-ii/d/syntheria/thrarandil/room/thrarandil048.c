#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("dirt path");
        set_short("Dirt Path");
        set_long("This part of town is undeveloped and rustic. Only a small dirt path connects this place to the rest of town. To the east is an endless grassy field, it stretches off far into the horizon. A few small trees dot the landscape, they are mere silhouettes at this distance.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "path"  : "A small dirt path, with tiny patches of grass.",
        ]));
        set_listen("default", "The sound of grass swaying in the wind fills the air.");
        set_smell("default", "The air is fresh and clean.");
        set_exits(([
			"north"     : ROOMS "thrarandil047.c",
			"south"     : ROOMS "thrarandil049.c",
        ]));
        
}

