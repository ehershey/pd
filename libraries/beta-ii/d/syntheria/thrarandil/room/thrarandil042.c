#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("dirt path");
        set_short("Dirt Path");
        set_long("The dirt path is covered with strange animal tracks, creatures must walk by here often. To the northwest is a large wooden shed, it looks rather old. Small patches of grass dot the path, it sways in the wind.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "shed"          :   "A large wooden shed, it has a small wooden door with a large lock on it.",
        ]));
        set_listen("default", "It is very quiet in this part of town.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"east"      : ROOMS "thrarandil069.c",
			"west"      : ROOMS "thrarandil043.c",
			"north"     : ROOMS "thrarandil041.c",
        ]));
        
}

