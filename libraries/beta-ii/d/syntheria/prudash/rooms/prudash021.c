#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("The fortress of Prudash, this is where the last stand would take place if the battle came to the village. There is a small hole on the north wall, it looks like it is used for archers to shoot at enemies. The walls are made from treated wood, the grain is very fine. There are several furs covering the floor, they look to come from large beasts not native to this island.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        "indoors"     : 1,
        ]) );
        set_items(([
    	"hole"         :   "A small hole angled towards the ground, it can be used by archers to shoot through.",
    	"fur"          :   "The fur of a large bear like creature, it must have been a mighty beast.",
        ]));
	    set_listen("default", "It is rather quiet.");
	    set_smell("default", "The sounds of burning torches echos through the halls.");
	    set_exits(([
			"southeast"	: ROOMS "prudash024.c",
			"southwest" : ROOMS "prudash022.c",
            "south"     : ROOMS "prudash020.c", 
        ]));
}

