#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("This room seems to serve almost no purpose. It is very bare, only a few torches hang on the walls. This room curves around to the northeast, and northwest. It would make it almost impossible for invaders to make it around this room without heavy casualties. This entire village seems to be designed to defend against attack.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        "indoors"     : 1,
        ]) );
        set_items(([
        "torches"      :   "Small torches fixed to the walls."
        ]));
	    set_listen("default", "It is rather quiet.");
	    set_smell("default", "The sounds of burning torches echos through the halls.");
	    set_exits(([
			"northwest"	: ROOMS "prudash022.c",
			"northeast" : ROOMS "prudash024.c",
            "north"     : ROOMS "prudash020.c", 
        ]));
}

