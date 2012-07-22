#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("This is the highest level in the tree village of Prudash. It serves as a makeshift barracks and castle. This is the only building in the village that appears to not be made from scrap wood, the entire building looks to have been made from fresh wood. The floor is covered with thick furs from beasts clearly not from this island. Large torches line the walls, providing much light.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        "indoors"     : 1,
        ]) );
        set_items(([
    	"torches"      :   "Large torches line the walls, they burn brightly.",
    	"fur"          :   "The fur of a large bear like creature, it must have been a mighty beast.",
        ]));
	    set_listen("default", "It is rather quiet.");
	    set_smell("default", "The sounds of burning torches echos through the halls.");
	    set_exits(([
			"down"	    : ROOMS "prudash009.c",
			"north"     : ROOMS "prudash021.c",
            "south"     : ROOMS "prudash023.c", 
        ]));
}

void reset() {
   ::reset();
if (!present("guard", this_object()))
     new(MOB"troll_guard.c")->move(this_object());
if (!present("guard 2", this_object()))
     new(MOB"troll_guard.c")->move(this_object());
}
