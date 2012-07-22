#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("dirt path");
        set_short("Dirt Path");
        set_long("This small dirt path raps around the back end of the cathedral. Along the path are many different beds of flowers, the clergy of the cathedral must tend this garden. The back end of the church has no windows on it, only one small door. To the north is a grassy field, and shortly after that a beach just before the sea. The sea stretches off into the horizon. A large wooden shed sits just to the east, it has a small door facing the west.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "cathedral"     :   "A large church with many elegant carvings.",
            "door"          :   "A small wooden door built into the cathedral. It has a large lock on the handle.",
            "lock"          :   "The lock is very rusty, it has not been used in many years.",
            "beach"         :   "A large sandy beach.",
            "flowers"       :   "A large assortment of brightly colored floweres.",
            "shed"          :   "A large wooden shed, it has a small wooden door with a large lock on it.",
        ]));
        set_listen("default", "It is very quiet in this part of town.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"west"      : ROOMS "thrarandil037.c",
			"southeast" : ROOMS "thrarandil043.c",
			"northeast" : ROOMS "thrarandil039.c",
        ]));
        
}

