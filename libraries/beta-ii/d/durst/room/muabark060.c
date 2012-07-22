#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("desert");
		set_short("The MuaBark desert");
		set_long("A large cyclone of sand makes navigation very difficult. The air is as thick as the sand below, breathing seems impossible. Death seems certain in this endless desert.");
		
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			
			
			"south"		: ROOMS "muabark062.c",
			"west"		: ROOMS "muabark061.c",
			"southeast"		: ROOMS "muabark059.c",
			
		]));
}


void reset()
{
    ::reset();
    if (children(MOB"nes_nomad.c")==({})||
        sizeof(children(MOB"nes_nomad.c")) < 2)
            new(MOB "nes_nomad.c")->move(this_object());
    if (!present("lizard", this_object()))
        new(MOB"md-lizard.c")->move(this_object());
}




